use heroku_89540cd1d015c2f;

DELIMITER $$  
CREATE PROCEDURE BC()

   BEGIN
      DECLARE a INT Default 1002;
      simple_loop: LOOP         
         insert into tbl_user(id,email,phone,password) values(a,a,a,a);
         SET a=a+1;
         IF a=1000000 THEN
            LEAVE simple_loop;
         END IF;
   END LOOP simple_loop;
END $$

CALL `BC`;