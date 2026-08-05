# Review A (reconstruction fidelity): `aa_00825bf0` UI_QuickBar_CreateSlotButton

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825bf0` |
| **VA** | `0x00825bf0` |
| **Canonical name** | `UI_QuickBar_CreateSlotButton` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00825bf0_UI_QuickBar_CreateSlotButton.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-place constructor** for a QuickBar **slot-button** NDUI widget: run base UI ctor, install derived vtable, zero/default derived fields, then load skin from **`i_d_qb_2d_btn_quickbar.xml`**. Returns `this`. **Not** a network send, **not** slot activate/cast, **not** page select.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00825bf0_FUN_00825bf0.md` |
| Annotated | `docs/reconstruction/raw/aa_00825bf0_FUN_00825bf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBar_CreateSlotButton.cpp` |
| Function record | `docs/reconstruction/functions/aa_00825bf0_UI_QuickBar_CreateSlotButton.md` |
| Live Ghidra | `decompile_function(0x00825bf0)` + `read_memory` on constants; callers/xrefs |
| Sole caller (context) | `FUN_008a16b0` @ `0x008a16b0` (two sites) |
| Related sibling (not this unit) | dtor `FUN_00825bb0`; XML attr `FUN_00825cd0` (`DOWN_SIZE_RATIO` → `+0x508`/`+0x504`) |

---

## 3. Signature / ABI

```c
// this = pre-allocated object (operator_new(0x554) at sole caller)
// returns this
void* /*object**/ UI_QuickBar_CreateSlotButton(void* this_);
```

| Claim | Confidence | Notes |
|---|---|---|
| `param_1` = `this` (object base) | **High** | Field stores; returns `param_1`; caller `operator_new(0x554)` then CALL |
| Object size **`0x554`** | **High** | Both call sites `operator_new(0x554)` before CALL |
| Returns `this` | **High** | Terminal `return param_1` |
| No stack formals beyond `this` | **High** | Body uses only `param_1` + globals |
| MSVC SEH frame (`LAB_009b42b0`) | **High** | ExceptionList chain around body |

---

## 4. Control flow (sealed)

```
SEH push (LAB_009b42b0)
FUN_00792d20(this)                         // base NDUI control/window ctor
                                           //   (installs base vtbl PTR_FUN_00a98f44, allocs subobjects)
this+0x508  = *(float*)DAT_00aaabc4        // default DOWN_SIZE_RATIO = 0.88f
this+0x510  = 0
this+0x50c  = 0
f = *(float*)g_flMultiKillCountBlend       // shared const pool @ 0x00a0f730 = 0.1f
*this       = &PTR_FUN_00a75004            // derived vtable (overrides base)
this+0x4fd  = 0                            // byte flags
this+0x4fe  = 0
this+0x540  = 0                            // dword[5] zero: +0x540..+0x550
this+0x544  = 0
this+0x548  = 0                            // later filled as child* by XML (label)
this+0x54c  = 0
this+0x550  = 0
this+0x4fc  = 0                            // selected/active flag (byte of [0x13f])
this+0x490  = 0                            // overrides base ctor's 1 at same offset
this+0xbf   = 0
this+0xc7   = 0
this+0x500  = 0xFFFFFFFF                   // column/slot index sentinel
this+0x514  = f                            // 0.1f
NDUIWindow_ReloadInterface("i_d_qb_2d_btn_quickbar.xml")  // thiscall; loads children
SEH pop
return this
```

---

## 5. Constants (`read_memory`)

| Symbol / VA | Bytes LE | Value | Role in this unit |
|---|---|---|---|
| `DAT_00aaabc4` | `ae 47 61 3f` | **0.88f** | Default at `this+0x508` |
| `g_flMultiKillCountBlend` @ `0x00a0f730` | `cd cc cc 3d` | **0.1f** | Stored at `this+0x514` — **shared float pool name; not multi-kill semantics** |
| `PTR_FUN_00a75004` | vtable base | derived methods | Installed after base ctor |
| String | — | `"i_d_qb_2d_btn_quickbar.xml"` | Skin for ReloadInterface |

Sibling `FUN_00825cd0` confirms `+0x508` is the `DOWN_SIZE_RATIO` float (also copies to `+0x504` when XML supplies it).

---

## 6. Field init map (this unit)

| Byte off | Dword idx | Init | Role (sealed / inferred) |
|---:|---:|---|---|
| `+0x00` | — | `PTR_FUN_00a75004` | Derived vtable |
| `+0xbf` | — | `0` | Flag byte |
| `+0xc7` | — | `0` | Flag byte |
| `+0x490` | `[0x124]` lo | `0` | Flag (base left `1`) |
| `+0x4fc` | `[0x13f]` lo | `0` | Selected/active (**High** from SelectPage sibling) |
| `+0x4fd` | — | `0` | Flag |
| `+0x4fe` | — | `0` | Flag (read by nearby `FUN_00825b30`) |
| `+0x500` | `[0x140]` | `-1` | Slot/column index sentinel (**High**; callers stamp 0/1; SelectPage uses as column) |
| `+0x508` | `[0x142]` | `0.88f` | Default `DOWN_SIZE_RATIO` |
| `+0x50c` | `[0x143]` | `0` | Residual (host page field is host+0x50c, not this widget) |
| `+0x510` | `[0x144]` | `0` | Residual |
| `+0x514` | `[0x145]` | `0.1f` | Float default |
| `+0x540..+0x550` | `[0x150..0x154]` | `0` | Five dwords; `+0x548` later = label child* after XML |

---

## 7. Callers / callees

### Callers (exactly 2 xrefs — both in one function)

| Site | Parent | Role |
|---|---|---|
| `0x008a19d2` | `FUN_008a16b0` | `operator_new(0x554)` → ctor → store `host[0x19b]` (`+0x66c`); stamp `+0x500=0`; label `"1"` via child `+0x548` |
| `0x008a1b1c` | `FUN_008a16b0` | same → store `host[0x19c]` (`+0x670`); stamp `+0x500=1`; label `"2"` |

No other xrefs (Ghidra `get_function_xrefs` / `get_function_callers`).

### Callees

| Callee | Role |
|---|---|
| `FUN_00792d20` | Base NDUI widget/window ctor (vtbl `PTR_FUN_00a98f44`, subobject news) |
| `NDUIWindow_ReloadInterface` | Load `"i_d_qb_2d_btn_quickbar.xml"` onto `this` |

---

## 8. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + base ctor | **Yes** |
| Field defaults + vtable swap | **Yes** |
| ReloadInterface string | **Yes** |
| Return this | **Yes** |
| No invented network/activate | **Yes** |

---

## 9. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = QB slot-button **ctor** | **High** | XML name + `operator_new` + field init pattern |
| Name from `i_d_qb_2d_btn_quickbar.xml` | **High** | String evidence; registry |
| Size `0x554` | **High** | Caller alloc |
| Vtable `PTR_FUN_00a75004` | **High** | Direct store; dtor `FUN_00825bb0` same vtbl |
| `+0x500` index sentinel `-1` | **High** | Init + caller stamp 0/1 |
| `+0x508` default 0.88 / DOWN_SIZE_RATIO | **High** | Const + sibling attr parser |
| `+0x514` = 0.1f shared pool | **High** | `read_memory` @ `0x00a0f730` |
| `+0x4fc` selected flag | **High** | Cross-unit SelectPage |
| `+0x548` becomes label child* | **High** | Caller null-check + sprintf path |
| Product English class name | **Inferred** | `UI_QuickBar_CreateSlotButton` is registry canonical from XML |
| Full vtable method map | **Open** | Not required to seal ctor |

---

## 10. Gaps / open

1. Product/RTTI name for the class (beyond XML + registry slug).
2. Full semantics of `+0x50c/+0x510/+0x514` and the non-label dwords in `+0x540..+0x550` beyond zero-init.
3. Whether the 10 page-column widgets use **this same class** or only the two hazard/page buttons in `FUN_008a16b0`.
4. Base ctor `FUN_00792d20` product name / layout (owned elsewhere).
5. Bit-for-bit / runtime / differential open.

**Verdict:** Ctor control flow, size, XML skin, key field defaults, and sole dual call sites sealed. Residual product names + unused field English. **accept-with-gaps.**
