use heroku_3b4f4710d6d9b37;

DELIMITER $$  
CREATE PROCEDURE BC()

   BEGIN
      DECLARE a INT Default 1;
      simple_loop: LOOP         
         insert into tbl_user(id,email,phone,password) values(a,CONCAT("user",a),a*10,CONCAT("pass",a));
         SET a=a+1;
         IF a=100 THEN
            LEAVE simple_loop;
         END IF;
   END LOOP simple_loop;
END $$

CALL `BC`;	