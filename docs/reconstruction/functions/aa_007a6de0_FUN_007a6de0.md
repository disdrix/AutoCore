# Function record: `StringPool_ApplyModeAndRingStore_Inferred` (`FUN_007a6de0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6de0` |
| **Canonical name** | `StringPool_ApplyModeAndRingStore_Inferred` |
| **Ghidra name** | `FUN_007a6de0` |
| **Address** | `0x007a6de0`–`0x007a70d0` (`ret 8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / string temp-pool (cross-cutting) |
| **Completion status** | **Partial** — three-rep scaffold + dual A/B **2026-07-29** (accept-with-gaps) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual A/B** | `reviews/A_aa_007a6de0_StringPool_ApplyModeAndRingStore_Inferred.md` · `reviews/B_aa_007a6de0_StringPool_ApplyModeAndRingStore_Inferred.md` |

## Alias

- Human / inferred: `StringPool_ApplyModeAndRingStore_Inferred`
- Weak plate (do not promote): `Named_CalleeOf_Client_RecvDestroyObject_007a6de0`

## Purpose

Mode-gated transform of a C-string into a **10-slot rotating temp buffer** on a pool object (`this`), returning the filled slot (or original `src` on early-out). Used pervasively for UI / chat / dialog literals.

Early-out → return `src`: null, empty, or strcmp-equal to sentinel **`"0"`** (`DAT_00a32460`).

Mode: stack arg, or `pool+0x2c` when arg is **`-1`**.

| Mode | OWN CF summary |
|---|---|
| 0 | helper `FUN_007a62c0` + strcpy into ring slot |
| 1–3 | helpers `FUN_007a6490` / `6410` (+ `6310`/`6610` if mode≠-1) |
| 4 | grow/zero buffer; **pig-latin** (vowels `a e i o u y`; suffixes `ay` / `yay`) |

Ring index `pool+0xc0` wraps at **10**; slots at `pool+4+i*4`; mode-4 caps at `pool+0x6c+i*4`.

## Signature (sealed)

```c
// __thiscall  ECX = pool*
// stack: const char *src, int mode
// ret 8
// returns: char* ring slot just written, or src on early-out
char *StringPool_ApplyModeAndRingStore_Inferred(void *pool, const char *src, int mode);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007a6de0_FUN_007a6de0.md`
- Annotated: `docs/reconstruction/raw/aa_007a6de0_FUN_007a6de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_007a6de0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007a6de0_StringPool_ApplyModeAndRingStore_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007a6de0_StringPool_ApplyModeAndRingStore_Inferred.md`

## Callers / callees

- **Callees (OWN list only):** `FUN_007a62c0`, `FUN_007a6310`, `FUN_007a6410`, `FUN_007a6490`, `FUN_007a6610`, `operator_new[]`, `operator_delete[]`
- **Callers:** 100+ xrefs (UI, auth, inventory, mission, skill) — e.g. `Client_RecvDestroyObject`, `Client_RecvInventoryAddItem`, `Skill_FormatFailureMessage`, `UI_BuildItemTooltipStats`, `CVOGReaction_GiveMission`

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / ring layout | **High** (dual A/B 2026-07-29) |
| `"0"` sentinel + mode `-1` → `+0x2c` | **High** |
| Mode 4 pig-latin structure | **High structural** |
| Modes 1–3 English / helpers | **Tentative / open** (OWN-only) |
| Product class / PDB name | **Open** (`_Inferred`) |
| Parameter semantic names | **Probable** (pool / src / mode) |
| Runtime / bit-exact | **Open** |
