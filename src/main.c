# include <stdio.h>
# include <png.h>

# define HEADER_BYTE_LENGTH 8

int main(int argc, char *argv[]) {
    puts("***** start *****\n");

    // コマンドライン引数が与えられなければプログラムを終了。
    if (argc < 2) {
        puts("I need filepath as fst param...\n");
        return -1;
    }

    // コマンドライン引数の第二要素(第一要素はプログラム名)をpath変数に代入。
    char* path = argv[1];

    // 指定されたファイルパスを開く。
    FILE *fp = fopen(path, "rb");

    // 指定されたファイルが無ければ、プログラムを終了。
    if (fp == NULL) {
        printf("%s Not Found...\n", path);
        return -1;
    }

    // ヘッダ用のデータを格納する領域を作成。
    char header[HEADER_BYTE_LENGTH];

    // 画像データから先頭の「HEADER_BYTE_LENGTH」分を格納。
    fread(header, 1, HEADER_BYTE_LENGTH, fp);

    // 先頭の数バイトからPNGフォーマットかどうか判断。
    int is_png = !png_sig_cmp(header, 0, HEADER_BYTE_LENGTH);
    // PNG画像と判断されなければ、プログラムを終了。
    if (!is_png) {
        printf("%s is not png...\n", path);
        return -1;
    }

    printf("%s is PNG formatted file!!!", path);

    puts("***** end *****\n");
}
