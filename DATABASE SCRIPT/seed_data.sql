use heroku_3b4f4710d6d9b37;

DROP PROCEDURE IF EXISTS seed_data;
DELETE FROM tbl_user WHERE id != 0;
DELETE FROM tbl_rank WHERE id != 0;
DELETE FROM tbl_role WHERE id != 0;
DELETE FROM tbl_category WHERE id != 0;

DELIMITER $$  
CREATE PROCEDURE seed_data()
BEGIN
	DECLARE cnt INT Default 1;
	user_loop: LOOP         
		insert into tbl_user(id,username,email,phone,password) values(cnt,CONCAT("user",cnt),CONCAT("user",cnt,"@email.com"),cnt*10,CONCAT("pass",cnt));
		SET cnt=cnt+1;
		IF cnt=10 THEN
			LEAVE user_loop;
		END IF;
	END LOOP user_loop;
    
	insert into tbl_rank(id,name) values(1,"DIAMOND");
    insert into tbl_rank(id,name) values(2,"PLATINUM");
    insert into tbl_rank(id,name) values(3,"GOLD");
    insert into tbl_rank(id,name) values(4,"SILVER");
    
    insert into tbl_role(id,name) values(1,"ADMIN");
    insert into tbl_role(id,name) values(2,"MODERATOR");
    insert into tbl_role(id,name) values(3,"NORMAL");
    
    insert into tbl_category(id,name,parent_id) values(1,"Tất cả sản phẩm",0);
    insert into tbl_category(id,name,parent_id) values(2,"Rau, củ, quả",1);
    insert into tbl_category(id,name,parent_id) values(3,"Trái cây",1);
    insert into tbl_category(id,name,parent_id) values(4,"Đồ khô",1);
    insert into tbl_category(id,name,parent_id) values(5,"Rau",2);
    insert into tbl_category(id,name,parent_id) values(6,"Củ",2);
    insert into tbl_category(id,name,parent_id) values(7,"Quả",2);
    insert into tbl_category(id,name,parent_id) values(8,"Trái cây 3 miền",3);
    insert into tbl_category(id,name,parent_id) values(9,"Trái cây nhập khẩu",3);
    
END $$

CALL `seed_data`;	