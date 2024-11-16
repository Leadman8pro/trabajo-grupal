--tabla main
create table categoria_principal(
id_categoria int primary key IDENTITY(1,1),
  nombre nvarchar(50)unique,

);

--Insertar datos
INSERT INTO categoria_principal(nombre)
values ('Accion'),
('Battle Royale'),
        ('ARPG')

--llamar tabla
select * from categoria_principal

--segunda tabla
CREATE TABLE desarrollador(

    id_desarrollador int primary key IDENTITY(1,1),
nombre nvarchar(50) unique

);

--Insertar datos
INSERT INTO desarrollador(nombre)
values ('Epic Games'),
	   ('Rockstar'),
       ('Cognosphere')

--LLamar tabla
select * from desarrollador


--Tabla para los juegos
CREATE TABLE juegos(
  id_juego int primary key identity(1,1) ,
  titulo nvarchar(100),
 id_categoria int ,
  id_desarrollador int ,
  precio varchar(100) default 'free',
  
  --Foreign key
  foreign key (id_categoria) references categoria_principal(id_categoria),
  foreign key (id_desarrollador) references desarrollador(id_desarrollador)
);



--Insertar Datos
INSERT INTO juegos(titulo, id_categoria, id_desarrollador)
VALUES ('GTA 6',1,2),
	   ('Genshin Impact', 3, 3 ),
       ('Fortnite',2 ,1 )
      
  --actulizar datos para que me ponga automatico el precio
  -- o que sea gratis
update juegos
set precio = '$165'
where id_juego = '1'

--Llamar la tabla
select * from juegos

--Tabla de inventario
CREATE TABLE inventario(

id_inventario int primary key,
  id_juego int,
  cantidad int,
  foreign key(id_juego) REFERENCES juegos(id_juego)

);

--Insertar datos de inventario
INSERT INTO inventario(id_inventario , id_juego, cantidad)
VALUES(1 , 1 , 3),
 	  (2 , 2 , 5),
      (3 , 3 , 6)


--Llamar tabla de inventario
select * from inventario


--Tabla de usuario
CREATE TABLE usuario(
id_usuario int primary key,
email varchar (100) unique,

);

--Insertar datos
INSERT INTO usuario(id_usuario , email)

VALUES(1, 'Joel@dewey'),
 	  (2, 'Christian@dewey'),
      (3, 'Nada@dewey')

--Llamar tabla de usuario
select * from usuario


--Tabla de compra
CREATE TABLE compra(
  id_compra int primary key,
  id_usuario int unique not null,
  id_juego int not null,
  fecha_compra date default getdate() not null,
  
  --Foreign key
  foreign key(id_juego) REFERENCES juegos(id_juego),
  foreign key(id_usuario) references usuario(id_usuario)
);

--Insertar datos
INSERT INTO compra(id_compra, id_usuario, id_juego)
VALUES(1532,2,1),
 (1533,3,2),
   (1534,1,3)
 
 --LLamar tabla
select * from compra




--Tabla de la tienda
CREATE TABLE tienda_de_juegos(
  id_tienda int primary key identity(1,1),
  id_inventario int not null unique,
  ubicacion varchar (100),
 
  --Foreign key
  foreign key (id_inventario) references inventario(id_inventario)
);

--Insertar datos
INSERT INTO tienda_de_juegos(id_inventario , ubicacion)

VALUES(3 , 'canovanas'),
 	  (2 , 'carolina'),
 	  (1 , 'rio grande')

--Llamar tabla
select * from tienda_de_juegos


/*
SELECT * FROM categoria AS CAT
INNER JOIN juegos AS JU
ON CAT.categoria_id = JU.categoria_id
*/