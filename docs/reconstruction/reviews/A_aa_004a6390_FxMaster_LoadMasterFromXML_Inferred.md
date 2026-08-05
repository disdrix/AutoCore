# Review A (reconstruction fidelity): `aa_004a6390` FxMaster_LoadMasterFromXML_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6390` |
| **VA** | `0x004a6390` |
| **Canonical name (Ghidra)** | `FUN_004a6390` |
| **Proposed name** | `FxMaster_LoadMasterFromXML_Inferred` (**Confirmed** plate `"LoadMasterFromXML"`) |
| **Prior scaffold alias** | `Named_VOG_DEBUG_STOP_004a6390` — string present but not sole role |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004a6390_FxMaster_LoadMasterFromXML_Inferred.md` |
| **System** | `client-fx` / FX master catalog populate |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Reload an FX master catalog from a named `_nfx.xml` script**: clear existing map values, open `..\scripts\<name>_nfx.xml` as tag `NDSpecialFX`, parse **every** root child node into an FX template, insert into the host map keyed by event id, detect duplicates.

Profiler enter/exit: `FUN_0076cf00("LoadMasterFromXML")` / `FUN_0076cef0`.

Requires global XML session `DAT_00b035fc != 0`. On entry sets host `+6 = 1`.

### Path rule (memory-verified)

```text
..\scripts\ + pszName + _nfx.xml
```

| Addr | Bytes / string | Role |
|---|---|---|
| `0x00a96040` | `2e 2e 5c 73 63 72 69 70 74 73 5c 00` → `..\scripts\` | Prefix (always copied) |
| `0x009ca184` | `5f 6e 66 78 2e 78 6d 6c 00` → `_nfx.xml` | **Always appended** (no `strstr` gate) |

Open: `NDXml_OpenTaggedDocument(path, "NDSpecialFX")`. **Return 0 = success** (inverted HRESULT-style).

### Parse / insert loop

For `i = 0 .. *(DAT_00b035fc+0xc) - 1`:

1. `node = FUN_00799900(i)` — null → log `VOG_DEBUG_STOP`, close, return 0
2. `fx = FUN_004a4fa0(node, &eventId, host+1, pszName)` — parse FX + out event id
3. If `fx`:
   - if `fx[+0x58] != -1` → host `+5 = 1`
   - `fx[+0xa] = 1` (master-owned / catalog flag)
   - `FUN_004a7580` insert `(eventId → fx)` into map
   - if insert reports duplicate (`local_12c == 0`): log `"Read duplicate event entry (%d) for FX file: %s"`, teardown + delete `fx`
4. `node->vtbl[+8](node)` release

Success path: `FUN_00798990` close doc, profile exit, **return 1**.  
Fail path (`LAB_004a6640`): profile exit, **return 0**.

### Pre-load clear

In-order walk of existing map: `FUN_004b85d0` + if value: `FUN_004b99c0` + `operator_delete`; then `FUN_004a6a40` free nodes and re-empty tree (size 0, sentinel self-links).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004a6390` |
| Raw / annotated / clean | `aa_004a6390` three-rep |
| Function record | `docs/reconstruction/functions/aa_004a6390_FUN_004a6390.md` |
| Path constants | `read_memory` `0x00a96040`, `0x009ca184` |
| Sibling single-FX load | `A_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` |
| Catalog ctor | `A_aa_004a1620_FxMasterCatalog_Ctor_Inferred.md` |
| Teardown | `A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md` |
| Ensure consumer | `A_aa_004eb3b0_Object_EnsureFxMasterFromDef_Inferred.md` |

**This pass:** live decompile; 12 xrefs; memory path strings. **Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature

```c
// thiscall: ECX = catalog host (from 004a1620)
// Stack: char* scriptBaseName (no path, no suffix required)
// Returns: 1 success, 0 failure
uint32_t __thiscall FxMaster_LoadMasterFromXML_Inferred(
    void *catalogHost,   // ECX
    char *scriptName);   // Stack[0x4]
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_0076cf00` / `FUN_0076cef0` | Profile LoadMasterFromXML |
| `FUN_004b85d0` / `FUN_004b99c0` / `operator_delete` | Clear map FX values |
| `FUN_004a6a40` | Free RB nodes / reset tree |
| `NDXml_OpenTaggedDocument` | Open path + tag |
| `FUN_00799900` | Indexed child node |
| `FUN_004a4fa0` | Parse SpecialFX node → FX* + event id |
| `FUN_004a7580` | Map insert (eventId → fx) |
| `FUN_007a4480` | Debug log |
| `FUN_00798990` | Close / release XML doc |

Callers (12): `FUN_004eb3b0`, `FUN_004f1c70`, `FUN_004f1e20`, `FUN_00531330`, `FUN_00542e20`, `FUN_00540610`, `FUN_005408f0`, `FUN_00542790`, `FUN_00581940`, `FUN_005c74e0`, `FUN_005d9af0`, …

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Profile enter string | Yes |
| Gate on `DAT_00b035fc` | Yes |
| Clear map values + rebuild empty | Yes (delete modeled noreturn — known Ghidra noise) |
| Path `..\scripts\` + name + `_nfx.xml` | Yes |
| Open tag `NDSpecialFX`, 0=ok | Yes |
| Multi-node parse + insert + dup log | Yes |
| Return 1 / 0 | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Plate name LoadMasterFromXML | **Confirmed** | string enter |
| Always-append `_nfx.xml` (no strstr) | **High** | body; contrast LoadFromScriptName |
| Multi-node catalog fill (not first-only) | **High** | loop vs `004a61b0` first node |
| Map key = event id from parse | **High** | insert pair + consumer `004a16d0` |
| Success return 1 / fail 0 | **High** | explicit |
| Open 0 = success | **High** | same family as LoadFromScriptName |
| `operator_delete` truly noreturn mid-clear | **Falsified as behavioral** | Ghidra mislabel; tree walk continues |
| Host `+5` = “has non-default event field” | **Probable** | set when `fx+0x58 != -1` |
| Product class English | **Tentative** | `_Inferred` ok with plate |

---

## 7. Gaps / open

1. Full type of map node / `FUN_004a7580` insert API (out-param `local_12c` = inserted?).
2. Exact meaning of `fx+0x58` and host `+5`.
3. Whether name already ending in `_nfx.xml` double-suffixes (body always appends).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — load/clear/parse/return High; host flag English Probable.
