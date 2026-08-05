# Review A (reconstruction fidelity): `aa_00720d40` CSoundManager_GetInstance

| Field | Value |
|---|---|
| **Stable ID** | `aa_00720d40` |
| **VA** | `0x00720d40` |
| **Canonical name** | `CSoundManager_GetInstance` (inferred; singleton accessor) |
| **Ghidra symbol** | `FUN_00720d40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00720d40_CSoundManager_GetInstance.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept** |

---

## 1. Purpose

**Once-init accessor** for the process-wide sound-manager singleton stored at **`DAT_00d20070`**.

Authoritative behavior:

1. If **`(DAT_00d20200 & 1) == 0`**: set bit0 of the once-flag, call **`FUN_00720a40(&DAT_00d20070)`** (ctor/init of manager object), register **`_atexit(LAB_009c3720)`** for process teardown.
2. Always return **`&DAT_00d20070`**.

Sibling evidence that the host is `CSoundManager`: `FUN_00723ab0` log string  
`"CSoundManager::_stopSound called with sound that was either already stopped(%d), or flagged to start playing(%d)"`  
and `FUN_007249c0` `"Sound file doesn't exist: %s"`. Methods that gate on **`this+600`** (`0x258`) use the same object layout as callers of this getter.

Callers (sample): `FUN_004b6fc0`, `FUN_004b7150`, `FUN_004b8dc0`, `FUN_00724180`, `FUN_007246d0`, many UI/FX sites; SEH catch at `0x009a021a`.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00720d40_FUN_00720d40.md` | ≡ live |
| Annotated | `docs/reconstruction/raw/aa_00720d40_FUN_00720d40.annotated.md` | ≡ raw |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00720d40.cpp` | CF ≡ raw |
| Function record | `docs/reconstruction/functions/aa_00720d40_FUN_00720d40.md` | scaffold |
| Live decompile | Ghidra MCP `0x00720d40` | **≡ raw** |
| Live memory | `DAT_00d20070` BSS zero at static image (runtime-filled) | OK |
| Related dual | `A_aa_004b8dc0` stop/clear path uses this getter | sealed |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No-args free function; returns `void*`/`CSoundManager*` | **High** | `return &DAT_00d20070` |
| Once flag bit0 at `DAT_00d20200` | **High** | `test / or 1` |
| Init via `FUN_00720a40(&DAT_00d20070)` | **High** | only on first call |
| `_atexit(LAB_009c3720)` registered once | **High** | body |
| Product family = `CSoundManager` | **High** | sibling `_stopSound` string |
| Exact English name `GetInstance` | **Probable** | pattern match; not PDB |
| `FUN_00720a40` full field init dual | **Open** | residual |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH frame setup (`LAB_009ac789`) | Yes |
| if once-bit clear → set bit, init, atexit | Yes |
| restore ExceptionList; return `&DAT_00d20070` | Yes |

```text
CSoundManager_GetInstance():
  if ((DAT_00d20200 & 1) == 0):
    DAT_00d20200 |= 1
    FUN_00720a40(&DAT_00d20070)
    atexit(LAB_009c3720)
  return &DAT_00d20070
```

---

## 5. Callers / callees

**Callees:** `FUN_00720a40`, `_atexit`.

**Callers:** many client FX/UI/audio sites (20+); see Ghidra callers list for `0x00720d40`.

---

## 6. Gaps / open

1. Dual unit for `FUN_00720a40` (ctor body / layout).
2. Dual unit for atexit `LAB_009c3720` dtor.
3. Full manager layout beyond slots used by play/stop family (`+0x210`, `+0x258`, `+0x31c`, …).
4. Runtime / bit-exact not run.

**Verdict:** **accept** — once-init singleton accessor sealed.
