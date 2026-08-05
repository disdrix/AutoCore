# Review A (reconstruction fidelity): `aa_0074e310` LightMgr_ListRegister_PushBack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e310` |
| **VA** | `0x0074e310` |
| **Body** | `0x0074e310`–`0x0074e375` inclusive (**102 B** / `0x66`); pad `CC` |
| **Canonical name** | `LightMgr_ListRegister_PushBack_Inferred` (**Inferred**); Ghidra `FUN_0074e310` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md` |
| **System** | Palantir light / effect-list manager |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context`, callee decompiles (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/append/refcount/bind sealed; product host English + vtbl+0x30 open |
| **Dual status** | **Present (W38-T)** |

---

## 1. Purpose

**Push-back register** a refcounted object onto the host's pointer vector, then bind:

| Offset | Role |
|---|---|
| `host+0x00` | identity dword passed to bind (`*host`) |
| `host+0x08` | vector **begin** (`T**`) |
| `host+0x0C` | vector **end** (`T**`) |

```
size = (begin == 0) ? 0 : (end - begin) >> 2;
FUN_00449440(host+4 view, size+1);   // resize → append one slot
slot = end - 1;
AddRef(obj);                         // +4; 0→1 → vtbl[+4]
Release(*slot);                      // if non-null; →0 → vtbl[+8]
*slot = obj;
obj->vtbl[+0x30](*host);
return 0;                            // ret 4
```

**ABI:** `__thiscall`; stack `(obj*)`; returns **0**; **`ret 4`**.

Peer family: single-slot `LightMgr_SetActiveSlot3c_Refcount_Inferred` (`0x0074e0d0`); unregister `FUN_0074e260` (same begin/end layout).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x0074e310` (2026-08-04) — incomplete on grow |
| Complete analysis | 10 xrefs; callee `FUN_00449440`; 7 caller funcs; worker |
| Machine | `read_memory` length 102 → full body + `C2 04 00` |
| Grow helper | `FUN_00449440` → `FUN_00449560` resize-to-N (begin@+4/end@+8 of `edx` base) |
| Callers | RebuildDefaultLights Direction/Hemi; Reflect resolve; BTLG path; others |
| Scaffold | `raw/aa_0074e310_*`, prior clean twin |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| this in EBX | `53 8b d9` | **Confirmed** |
| begin `this+8`, size via end-begin `>>2` | `8b 4b 08` … `8b 42 08 2b c1 c1 f8 02` with `edx=this+4` | **Confirmed** |
| resize `size+1` via `FUN_00449440` | `8d 48 01 e8 …` → `0x00449440` | **Confirmed** |
| slot = end-4 | `8b 7b 0c 83 ef 04` | **Confirmed** |
| AddRef + vtbl[+4] | `83 46 04 01` / `ff 50 04` | **Confirmed** |
| Release + vtbl[+8] | `83 41 04 ff` / `ff 52 08` | **Confirmed** |
| store + bind vtbl[+0x30](*this) | `89 37` / `8b 0b` push / `ff 50 30` | **Confirmed** |
| return 0 + **ret 4** | `33 c0 5b c2 04 00` | **Confirmed** |
| Body 102 B | last byte of ret @ `0x0074e375` | **Confirmed** |

Full hex (102 B):

```
538bd98b4b0885c98d53045657750433c0eb088b42082bc1c1f8028d4801e80db1cfff8b7b0c8b74241083ef0485f6741183460401837e040175078b068bceff50048b0f85c9740b834104ff75058b11ff520889378b0b8b06518bceff50305f5e33c05bc20400
```

---

## 4. Gaps

- Product C++ class for list host (`env+4` / Reflect aux).
- Product type of registered cores (callers pass `light+0x8c`).
- Exact English for `vtbl[+0x30]` bind contract.
- Grow insert zero-init policy (unowned `FUN_004497d0`) — usually makes Release no-op on fresh slot.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — append/refcount/bind/ABI sealed by bytes; decompiler grow hole closed via helper; product names open.
