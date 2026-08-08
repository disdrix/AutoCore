# Function record: Object_OnDeath

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519d80` |
| **Canonical name** | `Object_OnDeath` |
| **Ghidra name** | `FUN_00519d80` |
| **Address** | `0x00519d80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object lifecycle / combat death |
| **Completion status** | **Dual A/B sealed** (WQ9R-G 2026-08-04) — **accept-with-gaps** |
| **Naming basis** | Product format string embeds `ONDeath`; multi-vtbl method; peer `Object_QueueDelete` |

## Purpose

See `aa_00519d80_FUN_00519d80.md` and dual reviews A/B.

## Signature

```c
uint32_t __fastcall Object_OnDeath(void *self, int /*edx*/, int deathCtx);
```

## Artifacts

Same set as `aa_00519d80_FUN_00519d80.md` (raw / annotated / clean / duals / report).
