# Annotated low-level: Client_EncryptAndPrepareAuthRequest

| Field | Value |
|---|---|
| Stable ID | `aa_00728e50` |
| VA | `0x00728e50` |
| System | auth-login (inventory heuristic: missions-progression) |
| Date | 2026-07-23 |
| Refined | yes (clean rewrite of success/error paths + DES packing) |

## Machine-level notes

- Source: raw capture for `aa_00728e50` (`batch_decompile`).
- Source file string: `AuthClientImpl.cpp` under palantir Auth client lib.
- Success path returns `0`; failure paths log via `vog_LogMessage` with line immediates `0xC4` / `0xCB` / `0xD2` and return `0xFFFFFFFF`.
- Credential staging is a 30-byte stack buffer: `strncpy` username (14), then 16 password bytes, then **three** `DES_EncryptBlock8` steps advancing 8 bytes each → only bytes **0..23** encrypted; password tail (last 6 of 16) left clear. Plate comment matches body.
- `operator_new(0x38)` + `FUN_0071e420` allocate/construct AuthRequest; encrypted words land at `+0x10..`; `param_4` → `+0x30`, low 16 of `param_5` → `+0x34`.
- Socket-slot branch at `this+0x30` chooses `FUN_0046e280` vs `FUN_0067ba30`, then always `FUN_00727c00("Login","AuthServer")` and corresponding `FUN_0067b110` cleanup — setup for login scope, not the encrypt core.
- Prefer assembly if decompiler conflicts on the overlapping `CONCAT22` stores into `request+0x1e..+0x2a`.

## Open questions

- Semantic meaning of `param_4` / `param_5` (version? language? client build?).
- Exact ownership of `operator_new` buffer vs what `FUN_0071e420` returns (decompiler uses `iVar9` from ctor; alloc pointer not clearly linked — **Probable** that ctor uses the allocation via hidden this/out convention).
- DES key material: plate says `'NETD\0\0\0\0'` via `DES_InitializeCipher` path — not set inside this function.
- Confirm `FUN_0046ebf0` is the sole send handoff and that it consumes `param_5 = pRequest`.

## Pseudocode (annotated copy of raw)

See immutable raw body in `aa_00728e50_Client_EncryptAndPrepareAuthRequest.md`.
Clean behavior-preserving rewrite: `docs/reconstruction/reconstructed-exact/Client_EncryptAndPrepareAuthRequest.cpp`.
