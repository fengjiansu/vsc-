#ifndef _DMSUTIL_H
#define _DMSUTIL_H

#ifdef __cplusplus
extern ＾C￣ {
#endif

/*！！！！！！！！！！！！！！！！！！！！！！！！.
| md5 encrypt function
.！！！！！！！！！！！！！！！！！！！！！！！！*/
void EncryptMD5(unsigned char *output, unsigned char *input);
void EncryptMD5str(char *output, unsigned char *input, int len);

/*！！！！！！！！！！！！！！！！！！！！！！！！.
| hash encrypt function
.！！！！！！！！！！！！！！！！！！！！！！！！*/
void EncryptHash(char *crypt, char *source);

/*！！！！！！！！！！！！！！！！！！！！！！！！.
| DES encrypt and decrypt function
.！！！！！！！！！！！！！！！！！！！！！！！！*/
void EncryptDes(unsigned char *source, unsigned char *encrypt);
void DecryptDes(unsigned char *encrypt, unsigned char *source);

#ifdef __cplusplus
}
#endif

#endif