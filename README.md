# Philosophers

## Genel Bakış

Bu görevi başarmak istiyorsanız bilmeniz gereken şeyler şunlardır:

| Talimatlar | 
| :---        |
| • Bir veya daha fazla filozof yuvarlak bir masada oturuyor. Masanın ortasında büyük bir kase spagetti var. |
| • Filozoflar alternatif olarak yer, düşünür veya uyur. Yemek yerken ne düşünürler ne de uyurlar; düşünürken yemek yemiyor ve uyumuyorlar; ve tabii ki uyurken yemek yemiyor ve düşünmüyorlar. |
| • Masada filozoflar kadar çatal vardır. |
| • Spagettiyi tek çatalla servis etmek ve yemek çok zahmetli olduğundan, filozof yemek için sağdaki ve soldaki çatalları her iki eline birer tane alır. |
| • Bir filozof yemeğini bitirdiğinde çatallarını tekrar masaya koyar ve uyumaya başlar. Uyandıklarında tekrar düşünmeye başlarlar. Filozof açlıktan öldüğünde simülasyon durur. |
| • Her filozofun yemek yemesi gerekir ve asla aç kalmamalıdır. | 
| • Filozoflar birbirleriyle konuşmazlar. | 
| • Filozoflar başka bir filozofun ölmek üzere olup olmadığını bilmiyorlar. |
| • Filozofların ölmekten kaçınması gerektiğini söylemeye gerek yok! | 

## Argümanlar

Zorunlu kısım için bir program, bonus kısım için ayrı bir program yazmanız gerekiyor. Bonus kısmını yapmaya karar verirseniz, her ikisi de aşağıdaki kurallara uymak zorundadır:

• Program(lar)ınız aşağıdaki argümanları almalıdır:

| Argümanlar | Açıklama |
| :---        | --- |
| number_of_philosophers: | Filozofların sayısı ve ayrıca çatalların sayısı. |
| time_to_die (milisaniye cinsinden): | Filozofun yemek yemeden yaşayabileceği süre. |
| time_to_eat (milisaniye cinsinden): | Bir filozofun yemek yemesi için geçen süre. Bu süre zarfında iki çatal tutmaları gerekecek. |
|time_to_sleep (milisaniye cinsinden): | Bir filozofun uyuyarak geçireceği süre. |
|number_of_times_each_philosopher_must_eat (isteğe bağlı argüman): | Filozofların yemek yeme hedefi. |

## Programınızın logları hakkında:

• Bir filozofun herhangi bir durum değişikliği aşağıdaki gibi biçimlendirilmelidir:

	◦ timestamp_in_ms X çatal aldı
	◦ timestamp_in_ms X yiyor
	◦ timestamp_in_ms X uyuyor
	◦ timestamp_in_ms X düşünüyor
	◦ timestamp_in_ms X öldü
###
	timestamp_in_ms: milisaniye cinsinden geçen süre 
	X: Filozof numarası.

## Zorunlu kısım

Zorunlu kısım için özel kurallar şunlardır:

• Her filozof bir thread olmalıdır.

• Her filozof çifti arasında bir çatal vardır. Bu nedenle, birden fazla filozof varsa, her filozofun sol tarafında bir çatal, sağ tarafında bir çatal vardır. Sadece bir filozof varsa, masada sadece bir çatal olmalıdır.

• Filozofların çatalları çoğaltmasını önlemek için, çatalların durumunu her biri için bir muteks ile korumalısınız.

## Bonus kısım

Bonus bölümünün programı, zorunlu programla aynı argümanları alır.

Bonus kısmı için özel kurallar şunlardır:

• Tüm çatallar masanın ortasına konur.

• Hafızada durumları yoktur, ancak mevcut çatalların sayısı bir semafor ile temsil edilir.

• Her filozof bir süreç olmalıdır. Ama asıl süreç bir filozof olmamalıdır.