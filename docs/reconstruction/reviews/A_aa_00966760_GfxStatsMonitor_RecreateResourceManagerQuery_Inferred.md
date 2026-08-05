# Review A (reconstruction fidelity): `aa_00966760` GfxStatsMonitor_RecreateResourceManagerQuery_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00966760` |
| **VA** | `0x00966760` |
| **Body** | `0x00966760`–`0x0096678e` inclusive (**47 B** / `0x2F`); pad `CC` then sibling `@0x00966790` |
| **Canonical name** | `GfxStatsMonitor_RecreateResourceManagerQuery_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00966760_GfxStatsMonitor_RecreateResourceManagerQuery_Inferred.md` |
| **System** | graphics / gfxDevice Device Reset (Stats Monitor) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context`, parent decompile (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CreateQuery/type/out/always-0/EDI host sealed; product class English open |
| **Dual status** | **Present (W38-Z)** |

---

## 1. Purpose

Recreate the Stats Monitor's `IDirect3DQuery9` after device Reset:

```
dev = *DAT_00d1f044;                          // IDirect3DDevice9*
hr  = CreateQuery(dev, RESOURCEMANAGER/*5*/, &host->query@+0x3d4);
host->flag@+0x3d8 = 0;
if (hr < 0) host->query = null;
return 0;                                     // always
```

**ABI:** register **EDI = host\***; no stack formals; plain **RET**; always **EAX=0**.

Parent `FUN_0075eff0` (`gfxDevice.cpp` Device Reset) loads `EDI = *(device+0x79c)` and labels failure `"Failed to Reset() device on Stats Monitor"` — but always-0 return makes that arm **unreachable**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00966760` (2026-08-04) — **≡ raw** |
| Complete analysis | 1 xref; caller `FUN_0075eff0`; leaf; `unaff_EDI` |
| Machine | `read_memory` body **47 B** then `CC` |
| Parent context | decompile + `get_assembly_context` @ `0x0075f313` (`MOV EDI,[EBP+0x79c]`) |
| Device global | `DAT_00d1f044` (W35-R publish; first field = device9) |
| Scaffold | `raw/aa_00966760_*`, `reconstructed-exact/FUN_00966760.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Device via `DAT_00d1f044` double-load | `a1 44 f0 d1 00; 8b 00; 8b 08` | **Confirmed** |
| Out-arg `EDI+0x3d4` | `8d b7 d4 03 00 00` | **Confirmed** |
| Type imm 5 | `6a 05` | **Confirmed** |
| Vcall `+0x1d8` (CreateQuery) | `ff 91 d8 01 00 00` | **Confirmed** |
| Clear `EDI+0x3d8` | `c6 87 d8 03 00 00 00` | **Confirmed** |
| Fail → zero out | `7d 06; c7 06 00 00 00 00` | **Confirmed** |
| Always return 0 | `33 c0; 5e; c3` | **Confirmed** |
| Body 47 B | last `c3` @ `0x0096678e`; next `CC` | **Confirmed** |
| Parent EDI load | `8b bd 9c 07 00 00` @ `0x0075f30d` | **Confirmed** |

Full hex (47 B):

```
a144f0d1008b008b08568db7d4030000566a0550ff91d801000085c0c687d8030000007d06c7060000000033c05ec3
```

---

## 4. Gaps

- Product C++ class for host beyond log "Stats Monitor".
- Flag `+0x3d8` product English.
- Why CreateQuery HRESULT is swallowed.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — CF/ABI/D3D CreateQuery wiring sealed; product type name residual.
