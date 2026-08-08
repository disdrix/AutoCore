# Review A (reconstruction fidelity): `aa_00614c80` CVOGHBSkill_Master_Execute

| Field | Value |
|---|---|
| **Stable ID** | `aa_00614c80` |
| **VA** | `0x00614c80`–`0x00614d87` |
| **Body** | **264 bytes** (`0x108`) |
| **Canonical name** | `CVOGHBSkill_Master_Execute` |
| **Prior scaffold** | `FUN_00614c80` |
| **Review date** | `2026-08-05` (R11-011 dual seal) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00614c80_CVOGHBSkill_Master_Execute.md` |
| **System** | `skills-abilities` |
| **Partition parent** | `0x005788d0` `CVOGHBSkillBase_ctor` (callee) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/bulk xrefs + `read_memory` + `list_strings`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**`CVOGHBSkill_Master` virtual execute (vtbl+0x2c):** walk a stride-`0x10` target-descriptor table (cap 100), resolve each entry to a live object, and for every successful resolve allocate a **0x6c0** child skill HB, construct via **`CVOGHBSkillBase_ctor`** with that target, stamp Master vtbl **`PTR_FUN_009d0e6c`**, then **Enqueue+Start** on `map+0xe4ec` (or scalar-delete if owner `+0x18` is null). Always returns **1**.

Not the factory catalog (`0x0054a640` type id 3 registers a prototype only). Not `CVOGHBSkillBase_ctor` itself.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00614c80` |
| Bytes | `read_memory` 280 B — SEH, loop, rel32 calls, vtbl imm, `ret 0x18` |
| RTTI | COL `0x00aadb2c` → `.?AVCVOGHBSkill_Master@@` @ `0x00af28ac` |
| Vtbl | `read_memory` `0x009d0e6c` — slot +0x2c = this VA |
| Catalog | decompile `SkillElementFactory_RegisterCatalog` type id 3 |
| Resolve | decompile `CVOGReaction_ResolveObjectTarget` @ `0x004bae70` |
| Raw / annotated / clean | `aa_00614c80_*`, `CVOGHBSkill_Master_Execute.cpp` |
| Peer duals | SpawnEntities execute/ctor (vtbl+0x2c / size 0x6d0 contrast) |

**Not performed:** Launcher, runtime, parent ledgers, dual of Resolve/Enqueue/Start.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body bounds `00614c80`–`00614d87` | **Confirmed** | `get_function_by_address` + pad `CC` |
| `__thiscall` + `ret 0x18` (6 stack dwords) | **Confirmed** | `C2 18 00`; ECX save in prolog |
| Return `1` always | **Confirmed** | `B8 01 00 00 00` before epilogue; early sentinel same |
| Class RTTI `CVOGHBSkill_Master` | **Confirmed** | type_info string |
| This VA = vtbl+0x2c | **Confirmed** | DATA xref `009d0e98`; dword at slot |
| Catalog type id 3 / size `0x6c0` | **Confirmed** | factory arm |
| Loop max 100 / stride 0x10 | **Confirmed** | `cmp …, 0x64`; `shl …, 4` |
| Sentinel `-1,-1,type0` | **Confirmed** | decompile ≡ cmp chain |
| Resolve + ctor + Enqueue + Start order | **Confirmed** | rel32 targets |
| Owner test at `child+0x18` | **Confirmed** | `cmp dword [esi+0x18], 0` |
| Method English “Execute” | **High (convention)** | peer duals for +0x2c; no PDB string on VA |
| Stack formal product names | **Tentative** | skill/map/table roles from use |
| `*(map+0xe4e8)` type | **Open** | Resolve `this` only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog | Yes |
| do/while i&lt;100, stride 0x10 | Yes |
| Sentinel early return 1 | Yes |
| Resolve → optional new/ctor/vtbl | Yes |
| Owner null → dtor(1) else Enqueue+Start | Yes |
| Fall-through return 1 / ret 0x18 | Yes |

---

## 5. Gaps / open

1. Product method name beyond slot convention (PDB / string).
2. Producer of the target table (who fills arg4).
3. Concrete type of resolve context at `map+0xe4e8`.
4. Design of child Master re-stamp (same vtbl fan-out) vs alternate subclass.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
