GO
BEGIN
declare @i INT; 
declare @print varchar(1000)='';
set @i=1;
WHILE (@i<1000)
  BEGIN
  declare @j int = 1;
  declare @is_prime bit = 1;
  WHILE (@j<=@i)
     BEGIN 
         IF ((@i%@j)=0) and (@j!=1) and (@j!=@i)
           SET @is_prime = 0      
     SET @j = @j+1
     END
  IF (@is_prime=1) AND (@i!=1)
      IF(@i=2)
          SET @print+=CAST(@i as varchar) 
      ELSE
          SET @print+="&"+CAST(@i as varchar) 
  SET @i=@i+1
  END
END
PRINT @print;  
GO