# Fract-ol 42SP
<p align="center">
<strong>Renderizando fractais utilizando C Language</strong>
</p>

<div>
<img src="https://media-exp1.licdn.com/dms/image/C5622AQEvfrDnRC64dw/feedshare-shrink_800/0/1641496630603?e=2147483647&v=beta&t=bsn_VhOA1ks8Zq_JCQkhjnIZt8y1z74bUJt7d7jU_Q4" height="300em">
<img src="https://media-exp1.licdn.com/dms/image/C5622AQHhB_ND2DbK2Q/feedshare-shrink_800/0/1641496631104?e=2147483647&v=beta&t=8S_URAOmBSJSZQpY-NKpHYpUTJ_wlhzIG7iNHOv2nH4" height="300em">
</div>


## Features
- Renderiza dois tipos de fractais
	- Mandelbrot, que possuí uma estrutura padrão;
	- Julia, que sua estrutura varia de acordo com os valores passados.
- Diferente esquema de cores conforme o numero de iterações ocorridas.
- Possível dar zoom em qualquer parte do fractal.

## Compilação e execução
- Este projeto foi construído utilizando a biblioteca [minilibx](https://github.com/42Paris/minilibx-linux)
	- Para executá-lo, é necessário instalá-la em um ambiente Linux ou MacOs;
- Execute o comando `make` dentro da pasta root do projeto para compilá-lo.
- Execute então o arquivo **`./fractol <nome do fractal>`**.
	- Os possíveis nomes de fractais são:
		- mandelbrot
		- julia
- Para dar zoom, utilize o botão de rolagem do mouse.
