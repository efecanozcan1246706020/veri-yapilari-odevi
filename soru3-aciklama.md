# Soru 3: Trie (Metin Ağacı) Yapısı Nedir? Çalışma Şekli ve Algoritması

## Trie (Metin Ağacı) Nedir?

Trie, metin tabanlı verilerin (özellikle kelimelerin) hızlı ve verimli bir şekilde saklanması ve aranması için kullanılan bir ağaç (tree) veri yapısıdır. Her düğüm (node) bir karakteri temsil eder ve kökten yapraklara doğru gidildikçe bir kelimenin tamamı ortaya çıkar.

Trie, "retrieval" yani "erişim" kelimesinden türetilmiştir. Genellikle sözlük uygulamalarında, otomatik tamamlama (autocomplete), yazım denetimi ve IP yönlendirme gibi alanlarda kullanılır.

## Çalışma Şekli

- Trie, her düğümde harfleri barındırır ve her dal bir harfin devamını temsil eder.
- Aynı harflerle başlayan kelimeler aynı başlangıç yolunu kullanır. Örneğin:
    - "cat" ve "can" kelimeleri aynı `c` → `a` yolunu paylaşır.
- Kelime bittiği düğümde genellikle "son" işareti (örneğin: `isEndOfWord = true`) tutulur.
- Arama işlemi, her karakter için dallara bakılarak yapılır. Bu sayede arama işlemi O(n) zaman karmaşıklığına sahiptir (n = kelime uzunluğu).

## Algoritma (Açıklama)

Trie üzerinde temel 3 işlem yapılır:
1. **Ekleme (Insert)** → Her karakteri düğüm düğüm takip ederek yerleştirir.
2. **Arama (Search)** → Her karakter için düğümde ilerleyerek kelimenin var olup olmadığına bakar.
3. **Silme (Delete)** → Daha karmaşıktır, sadece başka kelimeler tarafından kullanılmayan dallar silinir.

## Kod

Kod için lütfen `soru3.c` dosyasına bakınız.
