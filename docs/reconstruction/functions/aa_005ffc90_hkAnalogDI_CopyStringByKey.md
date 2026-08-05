# Function record: hkAnalogDI_CopyStringByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc90` |
| **Canonical name** | `hkAnalogDI_CopyStringByKey` |
| **Ghidra name** | `FUN_005ffc90` |
| **Address** | `0x005ffc90`–`0x005ffce5` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Havok / DI analog string table |
| **Completion status** | **Dual A/B sealed (W25-M)** — raw append + annotated + clean + reviews |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005ffc90`
- Role: copy hashed C-string by uint key into caller buffer

## Purpose

thiscall worker on `hkAnalogDI`: open-address lookup in table at **this+8**; on hit `strncpy` mapped string to `dst` and return `strlen(src)`; on miss return **0**.

## Signature (sealed)

```c
int __thiscall hkAnalogDI_CopyStringByKey(
    void* this,          // hkAnalogDI*
    unsigned key,
    char* dst,
    unsigned maxlen);    // ret 0xc; EAX length or 0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ffc90_FUN_005ffc90.md` (+ W25-M append)
- Annotated: `docs/reconstruction/raw/aa_005ffc90_FUN_005ffc90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/hkAnalogDI_CopyStringByKey.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ffc90.cpp`
- Dual: `reviews/A_aa_005ffc90_hkAnalogDI_CopyStringByKey.md`, `reviews/B_aa_005ffc90_hkAnalogDI_CopyStringByKey.md`
- Scaffold record: `functions/aa_005ffc90_FUN_005ffc90.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller (1) | `hkAnalogDI_vtbl1` `0x005ffd80` @ site `0x005ffd97` |
| Callees | `FUN_00650290`, `FUN_0065ad10`, `FUN_0065acb0`, `FUN_00638040`, `FUN_00638060` |

## Confidence

| Claim | Level |
|---|---|
| Body bounds + `ret 0xc` | **High** (bytes) |
| thiscall + table at +8 | **High** (`lea esi,[ecx+8]`) |
| CF: lookup → found → copy → strlen / else 0 | **High** |
| Family name via caller `hkAnalogDI_*` | **High** |
| Product English for key domain | **Open** |
