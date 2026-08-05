# Review A (reconstruction fidelity): `aa_008dd590` CDlgFirstTime_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dd590` |
| **VA** | `0x008dd590` |
| **Body** | `0x008dd590`–`0x008dd66a` |
| **Canonical name** | `CDlgFirstTime_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008dd590_CDlgFirstTime_ctor.md` |
| **System tag** | `client-ui` / first-time-tips |
| **Live tools** | Ghidra `decompile_function` + `force_decompile` + `read_memory` + `get_function_callers` + `analyze_function_complete` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** MSVC constructor for the **first-time tip dialog** (`CDlgFirstTime`). Builds a `0x5B0`-byte NDUI dialog host: base dialog ctor → install class vtable `PTR_FUN_00a3d8b4` → zero tip-queue / widget slots → allocate empty tip-id list head → seed dialog defaults → bulk zero tip-specific fields → load skin **`"i_d_first.xml"`**. Returns `this`. Pure client UI scaffolding; **no packet send** in this body.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008dd590_FUN_008dd590.md` |
| Annotated | `docs/reconstruction/raw/aa_008dd590_FUN_008dd590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CDlgFirstTime_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_008dd590_FUN_008dd590.md` |
| Counterpart dual | `docs/reconstruction/reviews/B_aa_008dd590_CDlgFirstTime_ctor.md` |
| Caller dual (context) | `docs/reconstruction/reviews/A_aa_00801760_Client_MaybeShowFirstTimeTip.md` |

---

## 3. Signature / calling convention

| Claim | Confidence | Evidence |
|---|---|---|
| First arg = `CDlgFirstTime* this` (stack after SEH frame) | **High** | `analyze_function_complete` storage `Stack[0x4]`; machine `mov esi,[esp+0x1c]` post-frame; callers `CDlgFirstTime_ctor(operator_new(0x5b0))` |
| Returns `this` in EAX | **High** | `return param_1` in decompile; callers store return to `client+0x1164` / `DAT_00d1b9a4` |
| MSVC SEH frame | **High** | `ExceptionList` + unwind `LAB_009b709b`; prologue `push -1; push seh` |
| Object size **`0x5B0`** | **High** | Both callers: `operator_new(0x5b0)` |

```c
CDlgFirstTime *CDlgFirstTime_ctor(CDlgFirstTime *this);
```

---

## 4. Control-flow stages (clean ≡ raw ≡ force_decompile)

| # | Stage | Match | Notes |
|---|---|---|---|
| 1 | SEH install | Yes | `local_4=-1`, `ExceptionList` chain |
| 2 | Base dialog ctor | Yes | `FUN_0087b890(this, 0)` — base vtbl `PTR_FUN_00a58c6c`, zeros base dialog fields |
| 3 | Install class vtbl | Yes | `*this = &PTR_FUN_00a3d8b4` (`0x00a3d8b4`) |
| 4 | Zero 4 dword slots | Yes | indices `0x14e..0x151` → **+0x538..+0x544** |
| 5 | Tip-list head | Yes | `FUN_0040fb90()` → `operator_new(0xc)` circular self-links → **+0x54c**; **+0x550=0** |
| 6 | Dialog defaults | Yes | **+0x4fc=0x0f**, **+0x500=1**, **+0x52c=-1**, **+0x530=0**, bytes **+0x518/+0x519=0**, **+0x50c/+0x510/+0x514=0** |
| 7 | Bulk zero tip fields | Yes | `FUN_008dc1f0()` (fastcall ECX=this) zeros +0x4b4..+0x5ac block |
| 8 | Load interface XML | Yes | `FUN_008dc970(this, "i_d_first.xml")` → `NDUIWindow_ReloadInterface` |
| 9 | Restore SEH; return this | Yes | single return site |

**No invented modernizations** in clean plate: same CF / call order as raw + force decompile.

---

## 5. Field init map (ctor-owned stores)

| Dword idx | Byte off | Value | Role (inferred) | Conf |
|---|---:|---|---|---|
| `*this` | +0x00 | `PTR_FUN_00a3d8b4` | `CDlgFirstTime` vtbl | **High** |
| `[0x14e]` | +0x538 | 0 | child/widget ptr (zeroed before XML load) | **Probable** |
| `[0x14f]` | +0x53c | 0 | child/widget ptr | **Probable** |
| `[0x150]` | +0x540 | 0 | child/widget ptr | **Probable** |
| `[0x151]` | +0x544 | 0 | tip-queue count/cursor (caller `FUN_008c40a0` drains while `!=0`) | **High** (consumer) |
| `[0x153]` | +0x54c | `FUN_0040fb90()` | empty list/set sentinel (`0xC` circular node) | **High** |
| `[0x154]` | +0x550 | 0 | list size / companion | **Probable** |
| `[0x13f]` | +0x4fc | **0x0f** | dialog style/flags (base zeroed, then set) | **High** (value) |
| `[0x140]` | +0x500 | **1** | dialog mode/flag | **High** (value) |
| `[0x14b]` | +0x52c | **-1** | tip id sentinel / “none” | **High** (value); English **Probable** |
| `[0x14c]` | +0x530 | 0 | companion to tip id | **Probable** |
| byte `@[0x146]` | +0x518 | 0 | UI state byte (also cleared in load path) | **High** |
| byte | +0x519 | 0 | adjacent flag | **High** |
| `[0x143]` | +0x50c | 0 | tip-path zero | **High** |
| `[0x144]` | +0x510 | 0 | tip-path zero | **High** |
| `[0x145]` | +0x514 | 0 | tip-path zero | **High** |

`FUN_008dc1f0` additionally zeros (byte offs): `+0x4b4,+0x4b8,+0x4bc,+0x504,+0x508,+0x554..+0x5ac` (gap at +0x584) and calls `FUN_004133c0(0)` — full English of each slot still open.

---

## 6. Class vtbl `PTR_FUN_00a3d8b4` @ `0x00a3d8b4` (`read_memory`)

| Slot | +off | Target | Role (sealed where known) |
|-----:|-----:|---|---|
| 0 | +0x00 | `0x0040fd30` | scalar deleting dtor → `FUN_008dd500` (+ optional `operator_delete`) |
| 10 | +0x28 | `0x008dc970` | same as load helper used with `"i_d_first.xml"` |
| … | | (other slots UI base / overrides) | full English open |

Dtor path (`FUN_008dd500`): reinstalls same vtbl, `FUN_00415e90()`, `operator_delete(this[0x153])` — confirms **+0x54c** owns heap list head from ctor.

DATA xrefs to vtbl: ctor store + `FUN_008dd500` store only (class-private).

---

## 7. Callers (exactly **2**)

| Caller | VA | Alloc | Store | Role |
|---|---|---|---|---|
| `Client_MaybeShowFirstTimeTip` | `0x00801760` | `operator_new(0x5b0)` | `client+0x1164` | Lazy singleton; queue tip id via vfuncs |
| `FUN_008c40a0` | `0x008c40a0` | `operator_new(0x5b0)` | `DAT_00d1b9a4` | UI msg path (`param_1==8`, `param_2==0x9c41`); tip list UI |

Callees of **this** body only: `FUN_0087b890`, `FUN_0040fb90`, `FUN_008dc1f0`, `FUN_008dc970`.

---

## 8. Constants / strings

| Symbol | VA / value | Evidence |
|---|---|---|
| Class vtbl | `0x00a3d8b4` | imm store + `read_memory` |
| Base dialog vtbl (pre-overwrite) | `0x00a58c6c` | `FUN_0087b890` |
| Interface XML | `"i_d_first.xml"` @ `0x00a3e094` | load arg + `list_strings` |
| Related assets | `i_d_first_2d_btn_*` / `wnd_*` | string table near class data |
| Object size | `0x5B0` | both callers |

---

## 9. Gaps

1. Full English names for every +0x4xx field beyond sealed values.
2. Product name of base `FUN_0087b890` / `FUN_008dc1f0` / `FUN_008dc970` beyond observed roles.
3. Complete vtbl slot map for `PTR_FUN_00a3d8b4`.
4. Runtime / bit-exact / image-diff open.
5. Whether stack-this vs ECX-this is intentional ABI or analysis artifact (callers always pass one pointer; return this).

**Verdict:** **accept-with-gaps**
