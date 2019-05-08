use heroku_3b4f4710d6d9b37;

SET FOREIGN_KEY_CHECKS=0; -- to disable them
DROP PROCEDURE IF EXISTS seed_data;
DELETE FROM tbl_user WHERE id != 0;
DELETE FROM tbl_rank WHERE id != 0;
DELETE FROM tbl_role WHERE id != 0;
DELETE FROM tbl_category WHERE id != 0;
DELETE FROM tbl_shop WHERE id!= 0;
DELETE FROM ref_user_role WHERE id != 0;
DELETE FROM tbl_account WHERE id != 0;
SET FOREIGN_KEY_CHECKS=1; -- to re-enable them

DELIMITER $$  
CREATE PROCEDURE seed_data()
BEGIN
	DECLARE cnt INT Default 1;
    
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
    
	user_loop: LOOP         
		insert into tbl_user(id,username,email,phone,password) values(cnt,CONCAT("user",cnt),CONCAT("user",cnt,"@email.com"),cnt*10,CONCAT("user",cnt));
        insert into ref_user_role(id,tbl_user_id,tbl_role_id) values(cnt,cnt,3);
        SET cnt=cnt+1;
		IF cnt=5 THEN
			LEAVE user_loop;
		END IF;
	END LOOP user_loop;
    
	admin_loop: LOOP         
		insert into tbl_user(id,username,email,phone,password) values(cnt,CONCAT("admin",cnt),CONCAT("admin",cnt,"@email.com"),cnt*117,CONCAT("admin",cnt));
		insert into ref_user_role(id,tbl_user_id,tbl_role_id) values(cnt,cnt,1);
        SET cnt=cnt+1;
		IF cnt=8 THEN
			LEAVE admin_loop;
		END IF;
	END LOOP admin_loop;
    
	moderator_loop: LOOP         
		insert into tbl_user(id,username,email,phone,password) values(cnt,CONCAT("mod",cnt),CONCAT("mod",cnt,"@email.com"),cnt*129,CONCAT("mod",cnt));
		insert into ref_user_role(id,tbl_user_id,tbl_role_id) values(cnt,cnt,2);
        SET cnt=cnt+1;
		IF cnt=15 THEN
			LEAVE moderator_loop;
		END IF;
	END LOOP moderator_loop;
    
 
    insert into tbl_shop(id,name,description,image) values 
		(1,"Công Ty TNHH Chế Biến Nông Sản Thực Phẩm Thiên Hà",
		"Đơn vị chuyên cung cấp các loại Hoa quả nông sản Việt Nam như: Dừa già, Thanh long ruột đỏ, Xoài, Chanh dây trên toàn quốc và xuất khẩu sang một số quốc gia trên thế giới.",
        'C:\\Users\letrh\Desktop\Database\shopimg\1.txt');
    insert into tbl_shop(id,name,description,image) values 
		(2,"CN Công Ty TNHH Green Powers",
        "23C, Ấp 3, Xã Phú Nhuận, Tp. Bến Tre, Bến Tre, Việt Nam - 0907 158 228 - 0886 206 888",
        'C:\\Users\letrh\Desktop\Database\shopimg\2.jpg');
    insert into tbl_shop(id,name,description,image) values 
		(3,"Công Ty TNHH Nông Sản Thực Phẩm Xanh Xanh",
		"Xanh Xanh Foods - Hãy để chúng tôi đi chợ giúp bạn! ",
        'C:\\Users\letrh\Desktop\Database\shopimg\3.jpg');
    insert into tbl_shop(id,name,description,image) values 
		(4,"Nông Sản Vĩnh Phúc",
		"Nông Sản Vĩnh Phúc - Tự hào cung cấp cho thị trường các loại ĐU ĐỦ, CHUỐI TIÊU, ỔI, BƯỞI DA XANH & BƯỞI DIỄN thơm ngon, bổ dưỡng & tuyệt đối an toàn vệ sinh.",
        'C:\\Users\letrh\Desktop\Database\shopimg\4.jpg');
    insert into tbl_shop(id,name,description,image) values 
		(5,"Công Ty TNHH Cuộc Sống Tốt Lành",
		"Lô 1G, Khu Nông Nghiệp Công Nghệ Cao Tp. Hồ Chí Minh, Ấp 1, Xã Phạm Văn Cội, H. Củ Chi, Tp. Hồ Chí Minh (TPHCM), Việt Nam",
        'C:\\Users\letrh\Desktop\Database\shopimg\5.jpg');

	SET cnt = 1;
	account_loop: LOOP
		insert into tbl_account(id, name, city, address, gender, dob,tbl_user_id) values 
			(cnt,CONCAT("User bot",cnt), CONCAT("City sample", cnt),
            CONCAT("Address of bot",cnt),
            ROUND(RAND()),NOW() - INTERVAL FLOOR(RAND() * 100000) DAY,
            cnt);
		SET cnt = cnt+1;
		IF cnt=15 THEN
			LEAVE account_loop;
		END IF;
    end LOOP account_loop;
		

END $$

CALL `seed_data`;	

	