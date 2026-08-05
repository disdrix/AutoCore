# Function record: Client_EncryptAndPrepareAuthRequest

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728e50` |
| **Canonical name** | `Client_EncryptAndPrepareAuthRequest` |
| **Address** | `0x00728e50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth-login (emit heuristic tagged missions-progression) |
| **Completion status** | **Partial refined** — raw + annotated notes + clean rewrite; dual reviews / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Prepare login credentials for the auth client: validate username/password length, pack into a 30-byte buffer, DES-ECB encrypt the first 24 bytes (3×8), store into a 0x38-byte AuthRequest object, and hand off to the send path. Failure logs to `AuthClientImpl.cpp` with fixed line numbers.

## Signature (decompiler-derived)

```c
uint32_t Client_EncryptAndPrepareAuthRequest(
    int pAuthClient,
    char* pszUsername,
    char* pszPassword,
    uint32_t param4,
    int param5);
// returns 0 success, 0xFFFFFFFF failure
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00728e50_Client_EncryptAndPrepareAuthRequest.md`
- Annotated: `docs/reconstruction/raw/aa_00728e50_Client_EncryptAndPrepareAuthRequest.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_EncryptAndPrepareAuthRequest.cpp`

## Callers / callees

| Direction | Symbol / addr | Role |
|---|---|---|
| Callee | `DES_EncryptBlock8` `0x0071c1b0` | 8-byte DES block encrypt (×3) |
| Callee | `FUN_0071e420` | AuthRequest construct (0x38) |
| Callee | `FUN_0046ebf0` | Enqueue/send prepared request |
| Callee | `FUN_00727c00` | Login/AuthServer scope setup |
| Callee | `vog_LogMessage` | Error log with AuthClientImpl.cpp path |
| Related | `DES_InitializeCipher` `0x0071c000` | Key schedule (not called here) |
| Related | `AuthRequest_Serialize` `0x0071e460` | Request serialize helper |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| 14/16 length gates and error strings | High |
| DES ×3 on first 24 credential bytes | High (plate + loop) |
| Password tail 6 bytes unencrypted | High |
| `param_4` / `param_5` semantics | Tentative |
| Alloc vs ctor linkage for 0x38 object | Probable |
