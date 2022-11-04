# Philosophers

## Genel Bakış

Bu görevi başarmak istiyorsanız bilmeniz gereken şeyler şunlardır:

• Bir veya daha fazla filozof yuvarlak bir masada oturuyor.
Masanın ortasında büyük bir kase spagetti var.

• Filozoflar alternatif olarak yer, düşünür veya uyur.
Yemek yerken ne düşünürler ne de uyurlar;
düşünürken yemek yemiyor ve uyumuyorlar;
ve tabii ki uyurken yemek yemiyor ve düşünmüyorlar.

• Masada filozoflar kadar çatal vardır.

• Spagettiyi tek çatalla servis etmek ve yemek çok zahmetli olduğundan,
filozof yemek için sağdaki ve soldaki çatalları her iki eline birer tane alır.

• Bir filozof yemeğini bitirdiğinde çatallarını tekrar masaya koyar ve
uyumaya başlar. Uyandıklarında tekrar düşünmeye başlarlar. Filozof açlıktan öldüğünde simülasyon durur.

• Her filozofun yemek yemesi gerekir ve asla aç kalmamalıdır.

• Filozoflar birbirleriyle konuşmazlar.

• Filozoflar başka bir filozofun ölmek üzere olup olmadığını bilmiyorlar.

• Filozofların ölmekten kaçınması gerektiğini söylemeye gerek yok!

## Genel kurallar

Zorunlu kısım için bir program, bonus kısım için ayrı bir program yazmanız gerekiyor.
(bonus kısmını yapmaya karar verirseniz). Her ikisi de aşağıdaki kurallara uymak zorundadır:

• Global değişkenler yasaktır!

• Program(lar)ınız aşağıdaki argümanları almalıdır:

number_of_philosophers

time_to_die

time_to_eat

time_to_sleep

number_of_times_each_philosopher_must_eat

	◦ number_of_philosophers: Filozofların sayısı ve ayrıca çatalların sayısı.

	◦ time_to_die (milisaniye cinsinden): Bir filozof, son öğününden itibaren veya simülasyonun başlangıcından beri time_to_die milisaniyesi kadar yemek yemeye başlamadıysa ölür.

	◦ time_to_eat (milisaniye cinsinden): Bir filozofun yemek yemesi için geçen süre.
	Bu süre zarfında iki çatal tutmaları gerekecek.

	◦ time_to_sleep (milisaniye cinsinden): Bir filozofun uyuyarak geçireceği zaman.

	◦ number_of_times_each_philosopher_must_eat (isteğe bağlı argüman): Tüm filozoflar en az number_of_times_each_philosopher_must_eat kere yemek yemişse simülasyon durur. Belirtilmezse, bir filozof öldüğünde simülasyon durur.

• Her filozofun 1'den başlayarak number_of_philosophers kadar sayısı vardır.

• 1 numaralı filozof, number_of_philosophers filozofun yanında oturur.
N numaralı başka herhangi bir filozof, N - 1 numaralı filozof ile N + 1 numaralı filozof arasında oturur.

### Programınızın logları hakkında:

• Bir filozofun herhangi bir durum değişikliği aşağıdaki gibi biçimlendirilmelidir:

	◦ timestamp_in_ms X çatal aldı
	◦ timestamp_in_ms X yiyor
	◦ timestamp_in_ms X uyuyor
	◦ timestamp_in_ms X düşünüyor
	◦ timestamp_in_ms X öldü

	*timestamp_in_ms öğesini milisaniye cinsinden geçerli zaman damgasıyla ve X öğesini filozof numarasıyla değiştirin.*

• Görüntülenen bir durum mesajı başka bir mesajla karıştırılmamalıdır.

• Bir filozofun öldüğünü bildiren bir mesaj, filozofun gerçek ölümünden en fazla 10 ms sonra görüntülenmelidir.

• Yine filozoflar ölmekten kaçınmalıdır!

Programınız herhangi bir veri yarışına(data races) sahip olmamalıdır.

## Zorunlu kısım

|  Program Adı |  philo |
|---|---|
| Teslim Edilecek Dosyalar |   Makefile, *.h, *.c, in directory philo/ |
| Makefile | NAME, all, clean, fclean, re |
| Argümanlar | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]  |
| Fonksiyonlar  | memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| Libft | No  |

Zorunlu kısım için özel kurallar şunlardır:

• Her filozof bir thread olmalıdır.

• Her filozof çifti arasında bir çatal vardır. Bu nedenle, birden fazla filozof varsa, her filozofun sol tarafında bir çatal, sağ tarafında bir çatal vardır. Sadece bir filozof varsa, masada sadece bir çatal olmalıdır.

• Filozofların çatalları çoğaltmasını önlemek için, çatalların durumunu her biri için bir muteks ile korumalısınız.

## Bonus kısım

Bonus bölümünün programı, zorunlu programla aynı argümanları alır.

Global kurallar bölümünün gerekliliklerine uygun olmalıdır.

Bonus kısmı için özel kurallar şunlardır:

• Tüm çatallar masanın ortasına konur.

• Hafızada durumları yoktur, ancak mevcut çatalların sayısı bir semafor ile temsil edilir.

• Her filozof bir süreç olmalıdır. Ama asıl süreç bir filozof olmamalıdır.