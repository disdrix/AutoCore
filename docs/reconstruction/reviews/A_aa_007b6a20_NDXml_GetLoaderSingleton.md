# Review A (reconstruction fidelity): `aa_007b6a20` NDXml_GetLoaderSingleton

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6a20` |
| **VA** | `0x007b6a20`–`0x007b6a82` |
| **Canonical name** | `NDXml_GetLoaderSingleton` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (Meyers singleton / NDXml loader) |
| **Counterpart** | `reviews/B_aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| **System** | `client-xml` |
| **Verdict** | **accept-with-gaps** — ABI/CF/singleton layout sealed; full class/vtable product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. No `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

Return the process-static **NDXml path-loader** object at `DAT_00d20c38`, constructing it on first call (Meyers singleton):

1. Test once-guard `DAT_00d20c48` bit 0.
2. On first call: set guard, write object fields, `_atexit(LAB_009c3040)`.
3. Always `return &DAT_00d20c38`.

Primary consumer chain:

```
NDXml_OpenTaggedDocument (0x007999c0)
  → loader = NDXml_GetLoaderSingleton()     // THIS UNIT
  → NDXml_LoadDocumentFromPath(loader, doc, path)
```

Also called from terrain image/tint loaders, UI interface load, creature graphics setup, and 50+ other path/resource sites.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b6a20_NDXml_GetLoaderSingleton.md` (+ scaffold `FUN_007b6a20`) |
| Annotated | `docs/reconstruction/raw/aa_007b6a20_NDXml_GetLoaderSingleton.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_GetLoaderSingleton.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| Live decompile | `decompile_function` `0x007b6a20` ≡ raw |
| Live bytes | `read_memory` entry + tail; body end `0x007b6a82` |
| Callers | `get_function_callers` / complete analysis (≥50) |
| Sibling context (not owned) | `NDXml_LoadDocumentFromPath` `0x007b6c70`, `NDXml_OpenTaggedDocument` `0x007999c0`, dtor path `FUN_004239a0` / `FUN_007b65d0` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | No stack args; plain **`RET`** (`C3`) |
| Return | **Pointer in EAX** = `&DAT_00d20c38` |
| Body | `0x007b6a20`–`0x007b6a82` |
| Classification | worker (not leaf — calls `_atexit`) |

```c
void *NDXml_GetLoaderSingleton(void);
```

### 3.2 Control flow — **SEALED**

```
SEH prolog (FS:[0])
if (DAT_00d20c48 & 1) == 0:
  DAT_00d20c48 |= 1
  DAT_00d20c3c = 1                    // object+0x04
  DAT_00d20c38 = &PTR_FUN_00a95b88    // object+0x00 vtbl
  DAT_00d20c40 = 0                    // object+0x08
  DAT_00d20c44 = 0                    // object+0x0c
  _atexit(LAB_009c3040)
restore ExceptionList
return &DAT_00d20c38
```

Live decompile **≡** 2026-07-23 raw body (no CF delta).

### 3.3 Object layout at return — **SEALED (fields this unit writes)**

| Off | Init value | Consumer evidence |
|---|---|---|
| `+0x00` | `&PTR_FUN_00a95b88` | vtable; slot0 = `FUN_004239a0` scalar dtor |
| `+0x04` | `1` | `NDXml_LoadDocumentFromPath`: `(this+4)&1` enables search-path walk |
| `+0x08` | `0` | zeroed here |
| `+0x0c` | `0` | zeroed here; load-path fallback may fill later (`FUN_007b66c0`) |

Once guard `DAT_00d20c48` is **adjacent BSS**, not part of the returned object's documented consumer fields.

### 3.4 Role evidence — **High**

| Claim | Evidence |
|---|---|
| Path-loader `this` for XML load | `NDXml_OpenTaggedDocument` call site passes return → `NDXml_LoadDocumentFromPath` |
| Not a string helper | Zero stack args; returns fixed BSS address |
| Not VOG-ini exclusive | Named scaffold was incomplete; callers span UI/terrain/FX/creature |

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| Singleton CF + once-init | **High** | decompile + bytes |
| Return `&DAT_00d20c38` | **High** | `MOV EAX, imm32` |
| Init field values | **High** | direct stores |
| NDXml loader role | **High** | primary named consumers |
| Product class English name | **Probable** | inferred from NDXml_* chain |
| Vtable slots beyond dtor | **Tentative** | not owned |
| +0x08/+0x0c English | **Tentative** | zeroed only here |

---

## 5. Open questions

1. Official product type name for the singleton class.
2. Full vtable map for `PTR_FUN_00a95b88`.
3. Exact `LAB_009c3040` body vs `FUN_007b65d0` (atexit bytes touch `DAT_00d20c38` + call — sibling).
4. Runtime / image-diff verification.

**Verdict:** **accept-with-gaps** — unit is a small, fully sealed singleton getter; gaps are naming/product depth only.
