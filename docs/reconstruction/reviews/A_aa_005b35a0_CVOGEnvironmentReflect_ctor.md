# Review A (reconstruction fidelity): `aa_005b35a0` CVOGEnvironmentReflect_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b35a0` |
| **VA** | `0x005b35a0`–`0x005b366f` exclusive (**207 B** / `0xCF`) |
| **Canonical name** | `CVOGEnvironmentReflect_ctor` |
| **Prior scaffold** | `FUN_005b35a0` |
| **Review date** | `2026-07-29` (W32-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` |
| **System** | client / VOGEnvironmentSector / fog+reflect phase |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `get_function_by_address` + `get_function_xrefs` + `get_bulk_xrefs` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Complete ctor of owned **`CVOGEnvironmentReflect`** phase host (size **0x170**): base init, class vtbl, matrix sub at `+0x90`, parent nested wires, float stamp, enable flags.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` @ `0x005b35a0` ≡ 2026-07-23 raw CF |
| Bytes | `read_memory` 320 B — SEH `LAB_009a67ed`; vtbl `a0959d00`; `lea edi,[esi+0x90]`; float loads **1.0 / -1.0**; flags `+0x78`/`+0x80`; **`C2 04 00`** |
| Bounds | Ghidra `005b35a0`–`005b366e`; exclusive end **`005b366f`** (pad `CC`); dtor @ `005b3670` |
| RTTI | vtbl[-1] COL `0x00aafff8` → type_info `0x00af3eb0` → **`.?AVCVOGEnvironmentReflect@@`** |
| Caller | sole CODE `0x0048fdc7` in `FUN_0048fc90` — `new(0x170)` + parent@`+0xB8` → env`+0xC4` |
| Related | apply `005b36f0` (vtbl[1], W29-I); enable `005b39a0`; dtors `005b3670` / `005b3a30` |
| Raw / clean | `aa_005b35a0_*`, `CVOGEnvironmentReflect_ctor.cpp` |

**Not performed:** Launcher, runtime construct, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 207 B / `ret 4` / returns this | **Confirmed** | epilogue `8B C6` + `C2 04 00` |
| thiscall + parent stack arg | **Confirmed** | factory push parent |
| Vtbl / RTTI `CVOGEnvironmentReflect` | **Confirmed** | COL chain |
| Base `FUN_007560d0` then vtbl | **Confirmed** | |
| Matrix @ `+0x90` via `FUN_00972cc0` | **Confirmed** | `lea edi,[esi+90h]` |
| Parent wires `+0x15C` / `+0x160` / `+0x164` | **Confirmed** | decompile ≡ indices |
| Float stamp (1,-1,1) on matrix | **Confirmed** | `DAT_00a0f2a0`=1.0f, `DAT_00aaa668`=-1.0f |
| Flags `+0x78`/`+0x80`=1 | **Confirmed** | bytes `88 5e 78` / `88 9e 80 00 00 00` |
| Product English for base/matrix helpers | **Open** | |
| Runtime / differential | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
FUN_007560d0(this);
*this = &PTR_FUN_009d95a0;
FUN_00972cc0(this+0x90);
this[+0x15C]=parent; this[+0x158]=0;
this[+0x160]=*(parent+0xE4E8);
this[+0x150]=this[+0x154]=0;
this[+0x164]=*(parent+0xE894);
FUN_0044b440(this+0x90, 1.f, -1.f, 1.f);
if (this[+0x14C] & 1) FUN_00972e50(this+0x90);
*(u8*)(this+0x78)=1; *(u8*)(this+0x80)=1;
return this; // ret 4
```

| Stage | Match |
|---|---|
| Base → vtbl → matrix → wires → stamp → flags | Yes |
| Optional `FUN_00972e50` | Yes |
| ret 4 | Yes |

---

## 5. Gaps / open

1. Product demangle for `FUN_007560d0` base class.
2. Product names for `FUN_00972cc0` / `FUN_00972e50` / `FUN_0044b440`.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — sealed CF, ABI, RTTI, factory ownership; nested helper product English open.
