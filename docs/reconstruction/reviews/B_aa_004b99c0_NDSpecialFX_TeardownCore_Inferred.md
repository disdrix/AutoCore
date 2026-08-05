# Review B (skeptical / adversarial): `aa_004b99c0` NDSpecialFX_TeardownCore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b99c0` |
| **VA** | `0x004b99c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function never returns (operator_delete noreturn) | Ghidra warnings | **Falsified as true noreturn** — SEH continues; zeros after first deletes; body has multi-step CF |
| 2 | Identical to `FUN_004b85d0` | Both tear down FX | **Distinct** — `004b85d0` is list-only; this also frees `+0x3C`/`+0x60`, unregisters bit0, nukes map header |
| 3 | Full scalar deleting dtor including `delete this` | Ends in operator_delete | **Falsified** — deletes **owned** map/fields; callers still `operator_delete(fx)` |
| 4 | Audio play helper | Near `004b6fc0` | **Falsified** — only free/unlink paths |
| 5 | cdecl free function | Many xrefs | **Falsified** — ECX host |
| 6 | Product name known | scaffold chain | **Holds as false** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pre-delete teardown role | **High** | Leaks / double-free on port |
| List clearer is `004b85d0` | **High** | Orphan child FX |
| Map @ `+0x228` | **High** | Param-map leak |
| Bit0 registry semantics | **Probable** | Dangling registry entry |
| Exact owned types `+0x3C`/`+0x60` | **Tentative** | Wrong free size |

---

## 3. Cross-check against raw / live

```
SEH enter
if (fx[+0x3C]) delete; fx[+0x3C]=0
if (fx[+0x60]) delete; fx[+0x60]=0
FUN_004b85d0(fx)
if (*fx & 1) { unlink(fx); *fx &= ~1 }
clear_map(fx[+0x228]); delete fx[+0x228]
// body end 004b9a5c
```

34 xrefs including `NDSpecialFX_LoadFromScriptName` and `LoadMasterFromXML` flush loops.

---

## 4. Surviving contract for AutoCore

```
// Typical free:
NDSpecialFX_TeardownCore_Inferred(fx);
operator_delete(fx);
// Safe-ish if lists already empty (004b85d0 re-entry)
```

---

## 5. Open questions

1. Vtable dtor slot mapping (if any) vs free-function helper.
2. Identity of `+0x3C` / `+0x60` pointees.

**Verdict:** **accept-with-gaps**
