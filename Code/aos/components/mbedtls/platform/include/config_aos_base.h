/*
 * Copyright (C) 2019 Alibaba Group Holding Limited
 */

#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

/* System support */
#define MBEDTLS_HAVE_ASM
#define MBEDTLS_NO_UDBL_DIVISION
#define MBEDTLS_NO_64BIT_MULTIPLICATION
#define MBEDTLS_HAVE_TIME
#define MBEDTLS_PLATFORM_MEMORY

/* mbed TLS feature support */
#define MBEDTLS_CIPHER_PADDING_PKCS7
#define MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS
#define MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN
#define MBEDTLS_CIPHER_PADDING_ZEROS
#define MBEDTLS_REMOVE_ARC4_CIPHERSUITES
#define MBEDTLS_ERROR_STRERROR_DUMMY
#define MBEDTLS_GENPRIME
#define MBEDTLS_PKCS1_V15
#define MBEDTLS_PKCS1_V21
#define MBEDTLS_THREADING_ALT
#define MBEDTLS_VERSION_FEATURES

#if (MBEDTLS_CONFIG_CRYPTO_AES_ROM_TABLES > 0)
#define MBEDTLS_AES_ROM_TABLES
#endif
#if (MBEDTLS_CONFIG_CRYPTO_AES_FEWER_TABLES > 0)
#define MBEDTLS_AES_FEWER_TABLES
#endif

#if (MBEDTLS_CONFIG_CRYPTO_MODE_CBC > 0)
#define MBEDTLS_CIPHER_MODE_CBC
#endif
#if (MBEDTLS_CONFIG_CRYPTO_MODE_CFB > 0)
#define MBEDTLS_CIPHER_MODE_CFB
#endif
#if (MBEDTLS_CONFIG_CRYPTO_MODE_CTR > 0)
#define MBEDTLS_CIPHER_MODE_CTR
#endif
#if (MBEDTLS_CONFIG_CRYPTO_MODE_OFB > 0)
#define MBEDTLS_CIPHER_MODE_OFB
#endif
#if (MBEDTLS_CONFIG_CRYPTO_MODE_XTS > 0)
#define MBEDTLS_CIPHER_MODE_XTS
#endif

#if (MBEDTLS_CONFIG_SELFTEST > 0)
#define MBEDTLS_SELF_TEST
#endif

#if (MBEDTLS_CONFIG_TLS > 0)
#define MBEDTLS_KEY_EXCHANGE_RSA_ENABLED
#define MBEDTLS_SSL_ALL_ALERT_MESSAGES
#define MBEDTLS_SSL_ENCRYPT_THEN_MAC
#define MBEDTLS_SSL_EXTENDED_MASTER_SECRET
#define MBEDTLS_SSL_FALLBACK_SCSV
#define MBEDTLS_SSL_RENEGOTIATION
#define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH
#define MBEDTLS_SSL_PROTO_TLS1_2
#if (MBEDTLS_CONFIG_DTLS > 0)
#define MBEDTLS_SSL_PROTO_DTLS
#endif
#define MBEDTLS_SSL_ALPN
#define MBEDTLS_SSL_DTLS_ANTI_REPLAY
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY
#define MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE
#define MBEDTLS_SSL_DTLS_BADMAC_LIMIT
#define MBEDTLS_SSL_SESSION_TICKETS
#define MBEDTLS_SSL_EXPORT_KEYS
#define MBEDTLS_SSL_SERVER_NAME_INDICATION
#define MBEDTLS_SSL_TRUNCATED_HMAC
#endif /* MBEDTLS_CONFIG_TLS */

#if (MBEDTLS_CONFIG_X509 > 0)
#define MBEDTLS_X509_CHECK_KEY_USAGE
#define MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE
#define MBEDTLS_X509_RSASSA_PSS_SUPPORT
#endif

/* mbed TLS modules */
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C
#define MBEDTLS_BASE64_C
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_HKDF_C
#define MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_OID_C
#define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_MD_C
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PKCS5_C
#define MBEDTLS_PKCS12_C
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_THREADING_C
#define MBEDTLS_TIMING_C
#define MBEDTLS_VERSION_C
#define MBEDTLS_RSA_C

#if (MBEDTLS_CONFIG_CRYPTO_AES > 0)
#define MBEDTLS_AES_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_ARC4 > 0)
#define MBEDTLS_ARC4_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_BLOWFISH > 0)
#define MBEDTLS_BLOWFISH_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_CAMELLIA > 0)
#define MBEDTLS_CAMELLIA_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_ARIA > 0)
#define MBEDTLS_ARIA_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_MODE_CCM > 0)
#define MBEDTLS_CCM_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_MODE_GCM > 0)
#define MBEDTLS_GCM_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_CHACHA20  > 0)
#define MBEDTLS_CHACHA20_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_POLY1305 > 0)
#define MBEDTLS_POLY1305_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_CHACHAPOLY > 0)
#define MBEDTLS_CHACHAPOLY_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_DES > 0)
#define MBEDTLS_DES_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_XTEA > 0)
#define MBEDTLS_XTEA_C
#endif

#if (MBEDTLS_CONFIG_TLS_DEBUG > 0)
#define MBEDTLS_DEBUG_C
#endif
#if (MBEDTLS_CONFIG_ERROR > 0)
#define MBEDTLS_ERROR_C
#endif

#if (MBEDTLS_CONFIG_CRYPTO_MD5 > 0)
#define MBEDTLS_MD5_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_RIPEMD160 > 0)
#define MBEDTLS_RIPEMD160_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_SHA1 > 0)
#define MBEDTLS_SHA1_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_SHA256 > 0)
#define MBEDTLS_SHA256_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_SHA512 > 0)
#define MBEDTLS_SHA512_C
#endif

#if (MBEDTLS_CONFIG_TLS > 0)
#define MBEDTLS_SSL_CACHE_C
#define MBEDTLS_SSL_COOKIE_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_TLS_C
#endif

#ifdef LWM2M_WITH_MBEDTLS
#if (MBEDTLS_CONFIG_DTLS > 0)
#define MBEDTLS_SSL_SRV_C
#endif
#if (MBEDTLS_CONFIG_CRYPTO_AES > 0)
#define MBEDTLS_CTR_DRBG_C
#endif
#endif /* LWM2M_WITH_MBEDTLS */

#if (MBEDTLS_CONFIG_X509 > 0)
#define MBEDTLS_X509_USE_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_X509_CRL_PARSE_C
#endif

/* Module configuration options */
#if (MBEDTLS_CONFIG_TLS > 0)
#define MBEDTLS_SSL_MAX_CONTENT_LEN          MBEDTLS_CONFIG_TLS_MAX_CONTENT_LEN
#define MBEDTLS_TLS_DEFAULT_ALLOW_SHA1_IN_KEY_EXCHANGE
#endif

#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED

/* 
 * User custom configuration file to add or override the above default
 * configurations
 */
#if defined(MBEDTLS_CONFIG_USER_FILE)
#include MBEDTLS_CONFIG_USER_FILE
#endif

#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
