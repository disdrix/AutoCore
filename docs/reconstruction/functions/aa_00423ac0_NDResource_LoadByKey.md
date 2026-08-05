# Function record: NDResource_LoadByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423ac0` |
| **Canonical name** | `NDResource_LoadByKey` |
| **Address** | `0x00423ac0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `nd-resource` |
| **Completion status** | **accept-with-gaps** — three-rep + dual A/B sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

stdcall wrapper over the global ND resource cache: look up or create by key + default type token, write out-pointer, run resource virtual **+0x04** (init/load). Tristate return for null vs init result.

## Signature (machine-sealed)

```c
// __stdcall, ret 0x10
int NDResource_LoadByKey(void **pOutResource, void *pKey, void *pMatchCtx, int createPolicy);
// returns -1 (null), 0 (init false), 1 (init true)
// *pOutResource always written
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00423ac0_NDResource_LoadByKey.md`
- Annotated: `docs/reconstruction/raw/aa_00423ac0_NDResource_LoadByKey.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDResource_LoadByKey.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00423ac0_NDResource_LoadByKey.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00423ac0_NDResource_LoadByKey.md`

## Callers / callees

| Role | Symbol | VA |
|---|---|---|
| Caller | `NDXml_LoadDocumentFromPath` | `0x007b6c70` (call @ `0x007b6d8a`) |
| Callee | `FUN_00423b10` (type-token singleton) | `0x00423b10` |
| Callee | `NDResourceCache_LookupOrCreate` | `0x0075dba0` |
| Callee | indirect `vtbl+0x04` | resource instance |
| Global | `DAT_00d1f050` | cache pointer |

## Confidence

| Claim | Level |
|---|---|
| Control flow / tristate / always-write out | **High** |
| stdcall `ret 0x10` | **High** |
| Type token from `FUN_00423b10` | **High** |
| param3/param4 semantic names | **Tentative / Open** |
| Runtime verification | **Open** |
