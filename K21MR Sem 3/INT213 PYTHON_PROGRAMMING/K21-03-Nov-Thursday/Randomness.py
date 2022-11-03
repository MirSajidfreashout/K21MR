# Enter your code here. Read input from STDIN. Print output to STDOUT
alphabet = [chr(_) for _ in range(ord('a'), ord('z') + 1)]
keys_1 = [c for c in alphabet]
keys_2 = [c1+c2 for c1 in alphabet for c2 in keys_1]
keys_3 = [c1+c2 for c1 in alphabet for c2 in keys_2]
keys_4 = [c1+c2 for c1 in alphabet for c2 in keys_3]
keys_all = keys_1 + keys_2 + keys_3 + keys_4


def get_dict(depth=0):
    my_dict = {key: {'count': 0, 'all': set()} for key in keys_all}
    return my_dict


def get_map(string):
    string_len = len(string)
    char_map = get_dict()
    
    for i in range(string_len - 3):
        char_map[string[i]]['count'] += 1
        char_map[string[i]]['all'].add(i)
        char_map[string[i : i + 2]]['count'] += 1
        char_map[string[i : i + 2]]['all'].add(i + 1)
        char_map[string[i : i + 3]]['count'] += 1
        char_map[string[i : i + 3]]['all'].add(i + 2)
        char_map[string[i : i + 4]]['count'] += 1
        char_map[string[i : i + 4]]['all'].add(i + 3)
    
    char_map[string[-3]]['count'] += 1
    char_map[string[-3]]['all'].add(string_len - 3)
    char_map[string[-3:-1]]['count'] += 1
    char_map[string[-3:-1]]['all'].add(string_len - 2)
    char_map[string[-3:]]['count'] += 1
    char_map[string[-3:]]['all'].add(string_len - 1)
    
    char_map[string[-2]]['count'] += 1
    char_map[string[-2]]['all'].add(string_len - 2)
    char_map[string[-2:]]['count'] += 1
    char_map[string[-2:]]['all'].add(string_len - 1)
    
    char_map[string[-1]]['count'] += 1
    char_map[string[-1]]['all'].add(string_len - 1)
    
    return char_map


def update_queue_tree(queue, c, indices, s_map, s_len):
    count = 0
    followers = set(i+1 for i in indices)
    for next_c in alphabet:
        c2 = c + next_c
        next_candidates = s_map[c2]['all'].intersection(followers)
        if len(next_candidates) == 1:
            unique_wd_cnt = s_len - next_candidates.pop()
            count += unique_wd_cnt
        elif next_candidates:
            count += 1
            queue.append((next_c, next_candidates))
    return count


def efficient_count(string, char_map):
    string_len = len(string)
    count = 0
    for c in alphabet:
        if char_map[c]['count']:
            queue = []
            if char_map[c]['count'] == 1:
                unique_wd_cnt = string_len - list(char_map[c]['all'])[0]
                count += unique_wd_cnt
                continue
            
            count += 1
            for next_c in alphabet:
                c2 = c + next_c
                if char_map[c2]['count'] == 1:
                    unique_wd_cnt = string_len - list(char_map[c2]['all'])[0]
                    count += unique_wd_cnt
                elif char_map[c2]['all']:
                    count += 1
                    for next_next_c in alphabet:
                        c3 = c2 + next_next_c
                        if char_map[c3]['count'] == 1:
                            unique_wd_cnt = string_len - list(char_map[c3]['all'])[0]
                            count += unique_wd_cnt
                        elif char_map[c3]['all']:
                            count += 1
                            # queue.append((next_next_c, char_map[c3]['all']))
                            
                            for next_next_next_c in alphabet:
                                c4 = c3 + next_next_next_c
                                if char_map[c4]['count'] == 1:
                                    unique_wd_cnt = string_len - list(char_map[c4]['all'])[0]
                                    count += unique_wd_cnt
                                elif char_map[c4]['all']:
                                    count += 1
                                    queue.append((next_next_next_c, char_map[c4]['all']))
                            
            while queue:
                qc, c_indices = queue.pop()
                count_inc = update_queue_tree(queue, qc, c_indices, char_map, string_len)
                count += count_inc
            
    return count

def count_mutation(string, string_len, char_map, char_loc):
    mutation_count = 0
    for start in range(char_loc, -1, -1):
        dup_last_char = get_longest_duplicate(string, string_len, start, char_map, char_loc)
        if dup_last_char == char_loc:
            mutation_count += (start + 1) * (len(string) - dup_last_char)
            break
        mutation_count += len(string) - dup_last_char
    return mutation_count


def get_longest_duplicate(string, string_len, start, char_map, char_loc):
    """returns position of first char such that str[char_loc:position+1] has no duplicate"""
    if start == string_len - 1:
        # char_map and start are necessarily the same
        return char_loc + int(char_map[string[char_loc]]['count'] > 1)
    
    if char_map[string[start]]['count'] == 1:
        return char_loc
    
    candidates = char_map[string[start : start + 2]]['all']
    candidates_len = char_map[string[start : start + 2]]['count']
    
    if candidates_len == 1 or (start == char_loc and char_loc in candidates and candidates_len == 2):
        return max(char_loc, start + 1)
    
    if start + 1 == string_len - 1:
        return string_len
    
    candidates = char_map[string[start: start + 3]]['all']
    candidates_len = char_map[string[start: start + 3]]['count']
    if candidates_len == 1:
        return max(char_loc, start + 2)
    else:
        candidate_decr = 0
        if start == char_loc - 1:
            candidate_decr = int(char_loc in candidates)
        if start == char_loc:
            candidate_decr = int(char_loc in candidates) + int((char_loc + 1) in candidates)
        if candidates_len == 1 + candidate_decr:
            return max(char_loc, start + 2)
    
    if start + 2 == string_len - 1:
        return string_len
        
    candidates = char_map[string[start: start + 4]]['all']
    copied = False
    if (start + 3 > char_loc) and (char_loc in candidates):
        candidates = candidates.copy()
        copied = True
        candidates.remove(char_loc)
    if start + 3 > char_loc + 1 and (char_loc + 1 in candidates):
        if not copied:
            candidates = candidates.copy()
        candidates.remove(char_loc + 1)
    if start + 3 > char_loc + 2 and (char_loc + 2 in candidates):
        if not copied:
            candidates = candidates.copy()
        candidates.remove(char_loc + 2)
    
    current_pos = start + 3
    while len(candidates) > 1:
        current_pos += 1
        if current_pos == string_len:
            break
        candidates = set(x + 1 for x in candidates)
        candidates = char_map[string[current_pos - 3 : current_pos + 1]]['all'].intersection(candidates)
        
        if current_pos > char_loc:
            candidates.discard(char_loc)
            
    return char_loc if char_loc > current_pos else current_pos


def char_sub(string, s_map, pos, old_char, new_char):
    '''
    mofidies string_map when substituting one letter with another
    '''
    s_map[old_char]['count'] -= 1
    s_map[old_char]['all'].remove(pos)
    s_map[new_char]['count'] += 1
    s_map[new_char]['all'].add(pos)
    
    if pos > 0:
        p_char = string[pos - 1]
        p_char_old_1 = p_char + old_char
        p_char_new_1 = p_char + new_char
        
        s_map[p_char_old_1]['count'] -= 1
        s_map[p_char_old_1]['all'].remove(pos)
        s_map[p_char_new_1]['count'] += 1
        s_map[p_char_new_1]['all'].add(pos)
        
        if pos > 1:
            p_p_char = string[pos - 2]
            p_char_old_2 = p_p_char + p_char_old_1
            p_char_new_2 = p_p_char + p_char_new_1
            
            s_map[p_char_old_2]['count'] -= 1
            s_map[p_char_old_2]['all'].remove(pos)
            s_map[p_char_new_2]['count'] += 1
            s_map[p_char_new_2]['all'].add(pos)
            
            if pos > 2:
                p_p_p_char = string[pos - 3]
                p_char_old_3 = p_p_p_char + p_char_old_2
                p_char_new_3 = p_p_p_char + p_char_new_2
                
                s_map[p_char_old_3]['count'] -= 1
                s_map[p_char_old_3]['all'].remove(pos)
                s_map[p_char_new_3]['count'] += 1
                s_map[p_char_new_3]['all'].add(pos)
            
    
    if pos < len(string) - 1:
        n_char = string[pos + 1]
        n_char_old_1 = old_char + n_char
        n_char_new_1 = new_char + n_char
        
        s_map[n_char_old_1]['count'] -= 1
        s_map[n_char_old_1]['all'].remove(pos + 1)
        s_map[n_char_new_1]['count'] += 1
        s_map[n_char_new_1]['all'].add(pos + 1)
        
        if pos < (len(string) - 2):
            n_n_char = string[pos + 2]
            n_char_old_2 = n_char_old_1 + n_n_char
            n_char_new_2 = n_char_new_1 + n_n_char
            
            s_map[n_char_old_2]['count'] -= 1
            s_map[n_char_old_2]['all'].remove(pos + 2)
            s_map[n_char_new_2]['count'] += 1
            s_map[n_char_new_2]['all'].add(pos + 2)
            
            if pos < (len(string) - 3):
                n_n_n_char = string[pos + 3]
                n_char_old_3 = n_char_old_2 + n_n_n_char
                n_char_new_3 = n_char_new_2 + n_n_n_char
                
                s_map[n_char_old_3]['count'] -= 1
                s_map[n_char_old_3]['all'].remove(pos + 3)
                s_map[n_char_new_3]['count'] += 1
                s_map[n_char_new_3]['all'].add(pos + 3)
    
    if (pos > 0) and (pos < len(string) - 1):
        p_n_old = p_char + old_char + n_char
        p_n_new = p_char + new_char + n_char
        
        s_map[p_n_old]['count'] -= 1
        s_map[p_n_old]['all'].remove(pos + 1)
        s_map[p_n_new]['count'] += 1
        s_map[p_n_new]['all'].add(pos + 1)
        
        if pos < len(string) - 2:
            p_n_n_old = p_n_old + n_n_char
            p_n_n_new = p_n_new + n_n_char
            
            s_map[p_n_n_old]['count'] -= 1
            s_map[p_n_n_old]['all'].remove(pos + 2)
            s_map[p_n_n_new]['count'] += 1
            s_map[p_n_n_new]['all'].add(pos + 2)
        
        if (pos > 1) and (pos < len(string) - 1):
            p_p_n_old = p_p_char + p_n_old
            p_p_n_new = p_p_char + p_n_new
            
            s_map[p_p_n_old]['count'] -= 1
            s_map[p_p_n_old]['all'].remove(pos + 1)
            s_map[p_p_n_new]['count'] += 1
            s_map[p_p_n_new]['all'].add(pos + 1)

if __name__ == '__main__':
    N, Q = [int(_) for _ in input().split()]
    input_str = input()
    input_str_len = len(input_str)

    modification = []
    for _ in range(Q):
        pos, new_char = input().split()
        modification.append((int(pos) - 1, new_char))
    
    cmap_new = get_map(input_str)
    sub_count_new = efficient_count(input_str, cmap_new)

    for pos, new_char in modification:
        # pos, new_char = input().split()
        # pos = int(pos) - 1
        old_char = input_str[pos]

        # if old_char != new_char:
        mut_old = count_mutation(input_str, input_str_len, cmap_new, pos)
        input_str = input_str[:pos] + new_char + input_str[pos + 1:]
        char_sub(input_str, cmap_new, pos, old_char, new_char)
        mut_new = count_mutation(input_str, input_str_len, cmap_new, pos)
        sub_count_new += - mut_old + mut_new
        print(sub_count_new)