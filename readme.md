# libpngライブラリテスター(for C)

libpngライブラリの動作確認をするための簡単なモジュールです。  
libpngライブラリに所属するpng_sig_cmp関数を使用して指定したファイルがPNGフォーマットかどうかを判定します。  


# 環境情報

| 機能 | バージョン |
| ---- | ---- |
| Linux / Ubuntu | 20.4.5 |
| C(gcc) | 9.4.0 |


# 環境構築

## aptのアップデート

```bash
sudo apt update
sudo apt upgrade
```

## C開発環境に必要なモジュールのインストール

```bash
sudo apt install build-essential
```

## libpngのインストール

```bash
wget https://download.sourceforge.net/libpng/libpng-1.6.38.tar.gz
tar xvfz libpng-1.6.38.tar.gz
cd libpng-1.6.38
./configure --prefix=/usr/local/libpng/1_6_38
make
make install

# インストールが完了したら、不要なファイル群は削除
cd ../
rm -r -f libpng-1.6.38
rm -r -f libpng-1.6.38.tar.gz
```

---

ってか、以下のコマンドでもok!ですね、、、  
こっちの方が簡単だぁ、、、

```bash
sudo apt install libpng-dev
```
