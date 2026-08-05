# Review A (reconstruction fidelity): `aa_0089b090` UI_RefinePanel_BindRecipeDisplay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089b090` |
| **VA** | `0x0089b090` |
| **Canonical name** | `UI_RefinePanel_BindRecipeDisplay_Inferred` |
| **Prior names** | `FUN_0089b090`, `Named_key_dds`, `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0089b090` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0089b090_UI_RefinePanel_BindRecipeDisplay_Inferred.md` |
| **System** | `inventory-transfer` (refinery UI) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind / refresh the **refinery (recipe) panel** chrome from a selected commodity (or reverse-refine product):

```text
// this = refine UI host (param_1 / stack this)
if (!host.vtbl[+0x3d8]() || !DAT_00d1b6d8) return;
FUN_007a69d0();  // locale / string setup
// clear two side widgets host[0x183]/[0x184] via vtbl+4
host[0x14a] = 0;  // mode: 0 clear / 1 multi-input / 2 single-output

// resolve selected coid: host[0x15a].vtbl+0x44c, else host[0x15b]
// if both -1: wipe 5 ingredient slots, clear icons/labels, hide Recipe/Refines UI; return

entry = CNDHash_LookupByKey(*(DAT_00d1b570+0xf10), coid)
// optional reverse path when host[0x14e] flag: re-lookup via commodity+0x4d0 product key

// branch on FUN_00599dd0() count + host[0x183] gate:
//   mode 1: fill up to N ingredient rows (name "%S"/"%S: %i", icon path, "%i/1")
//   mode 2: single product row + tech gate FUN_005711c0 sum vs byte commodity+0x4c9 ("%i/%i")
// pad remaining of 5 slots clear
// main icon: "%s_key_i.dds" if entry.type==0xe else "%s_i.dds"
// labels: "Recipe:" / "Refines Into:" / "Reverse Refines Into:" / "Cannot Reverse Refine"
```

**Not** packet IO — pure UI rebind. Parent `FUN_0089c6c0` (refinery window refresh; also from `Client_RecvInventoryAddItem`).

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| **Stack / this** | Refine UI host `int*` | Callers `PUSH EDI` then `CALL`; body uses `param_1` as large UI object |
| Return | `void` | Fall-through `ExceptionList` restore |
| Epilogue | `ret` (no stack pop of args — cdecl-ish after push this) | Caller sites push EDI |

SEH frame `LAB_009ad239`. Prologue: FS exception chain + `sub esp, 0x24…` (large locals for sprintf buffers).

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0089b090_FUN_0089b090.md` |
| Annotated | `docs/reconstruction/raw/aa_0089b090_FUN_0089b090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0089b090.cpp` (+ alias scaffold) |
| Function record | `docs/reconstruction/functions/aa_0089b090_FUN_0089b090.md` |
| Live decompile | Ghidra `batch_decompile` `0x0089b090` (2026-07-29) |
| Live bytes | `read_memory` `0x0089b090` length 24 — SEH prologue |
| Callers | 4× `UNCONDITIONAL_CALL` all in `FUN_0089c6c0` (`0x0089c7ae`, `0x0089cb2a`, `0x0089cb93`, `0x0089cdc8`) |
| Call-site | `get_assembly_context` @ `0x0089c7ae`: `PUSH EDI; CALL`; next `MOV ESI,EDI; CALL 0x0089c330` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `vtbl+0x3d8` + `DAT_00d1b6d8` | **Yes** |
| Dual select widgets `0x15a` / `0x15b` → coid or wipe-5 | **Yes** |
| Hash lookup `DAT_00d1b570+0xf10` | **Yes** |
| Reverse flag `host[0x14e]` + product key `commodity+0x4d0` | **Yes** |
| Mode byte `host[0x14a]` ∈ {0,1,2} | **Yes** |
| 5-slot ingredient strip (stride-1 int arrays around `+0x169`) | **Yes** |
| Strings Recipe / Refines / Reverse / `%s_key_i.dds` | **Yes** |
| Clean scaffold plate only | **Weak** — CF matches; names residual |

### Key offsets (body-backed, dword indices on `int* this`)

| Index / byte | Role |
|---|---|
| `[0x14a]` | UI mode 0/1/2 |
| `[0x14e]` (byte) | reverse-refine UI mode |
| `[0x15a]/[0x15b]` | select widgets (`vtbl+0x44c` → coid) |
| `[0x169]` ±5 / +5 / +10 | 5× icon / label / qty widgets + coid stash |
| `[0x17a]/[0x178]/[0x179]` | main icon / secondary / name widgets |
| `[0x17b]` | bound coid (−1 clear) |
| `[0x183]/[0x184]` | optional side chrome cleared at entry |
| commodity `+0x4d0` | product / reverse key |
| commodity `+0x4c9` (byte) | tech requirement threshold |
| entry `+0x38` | type (`0xe` → key icon path) |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Role = refinery recipe panel rebind | **High** (string-sealed) |
| Canonical `UI_RefinePanel_BindRecipeDisplay_Inferred` | **Probable** |
| PDB / retail symbol | **Open** |

---

## 6. Gaps

- Exact product English for mode 1 vs 2 (forward multi-input vs single product).
- Widget class names behind vtbl slots `0x1d8`/`0x15c`/`0xcc`/`0x34c`/`0x50`/`0x2c4`.
- Runtime / bit-exact open.

---

## 7. Verdict

**accept-with-gaps** — CF, string labels, hash lookup, and dual A≡B sealed from live decompile + parent call sites. Product widget class names residual.
