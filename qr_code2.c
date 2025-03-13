#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Failed to generate QR code\n");
        return;
    }

    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file\n");
        QRcode_free(qrcode);
        return;
    }

    fprintf(file, "P1\n%d %d\n", qrcode->width, qrcode->width);
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            fprintf(file, "%d ", qrcode->data[y * qrcode->width + x] & 1 ? 0 : 1);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    QRcode_free(qrcode);
    printf("QR Code generated and saved to %s\n", filename);
}

int main() {
    const char *text = "https://example.com";
    const char *filename = "qrcode.pbm";
    generate_qr_code(text, filename);
    return 0;
}
