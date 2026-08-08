# Review A (reconstruction fidelity): `aa_00621700` CVOGHBSkill_OnDoHit_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621700` |
| **VA** | `0x00621700`–`0x00621807` |
| **Body** | **264 bytes** (`0x108`) |
| **Canonical name** | `CVOGHBSkill_OnDoHit_Execute_Inferred` |
| **Prior scaffold** | `FUN_00621700` |
| **Review date** | `2026-08-05` (R11-018 dual seal) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkill_OnDoHit |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `get_xrefs_to` + `get_function_callees` + `analyze_function_complete`. **No** `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

`CVOGHBSkill_OnDoHit` **vtbl+0x2C** multi-target arm:

1. Walk TFID table at `param_4` (stride `0x10`) until sentinel `{-1,-1,bGlobal=0}`.
2. Resolve each entry via `CVOGReaction_ResolveObjectTarget` (`ctx = world+0xe4e8`).
3. On hit: `new(0x6c0)` → `CVOGHBSkillBase_ctor` + install `PTR_FUN_009d15c4` (same class).
4. If `owner@+0x18` set: `CVOGHBList_Enqueue(world+0xe4ec)` + `CVOGHBBase_Start`; else `vtbl[0](1)`.
5. Always **return 1** at sentinel.

Not the subclass ctor (`FUN_00621350`); this unit **inlines** that ctor's base+vtbl sequence per target.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x00621700` — **CF ≡** raw 2026-07-23 |
| Disassembly | `disassemble_function` full body through `ret 0x18` |
| Bytes | `read_memory` 280 B — sizes, rel32, vtbl imm, list/resolve offsets |
| RTTI | COL `0x00aae1a0` → type_info `0x00af1d80` → `.?AVCVOGHBSkill_OnDoHit@@` |
| Xref | sole DATA `0x009d15f0` = vtbl+0x2C |
| Peer ctor | `FUN_00621350` installs same vtbl (R11-017 partition; evidence only) |
| Raw / clean | `aa_00621700_*`, `CVOGHBSkill_OnDoHit_Execute_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of ctor/siblings.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00621700`–`00621807`, 264 B | **Confirmed** | function meta + `ret` site |
| `ret 0x18` / six stack formals | **Confirmed** | `C2 18 00` |
| Return EAX=1 on sentinel | **Confirmed** | `B8 01 00 00 00` |
| ECX this unused | **Confirmed** | no `mov reg,ecx` consumer |
| Stride `0x10` TFID table + sentinel | **Confirmed** | `shl 4` + triple compare |
| Resolve ctx `world+0xe4e8` | **Confirmed** | `mov ecx,[ebp+0xe4e8]` |
| Alloc size `0x6c0` | **Confirmed** | `push 0x6c0` |
| Base = `CVOGHBSkillBase_ctor` @ `005788d0` | **Confirmed** | rel32 + named decomp |
| Vtbl imm `009d15c4` | **Confirmed** | `C7 06 C4 15 9D 00` |
| Class RTTI `CVOGHBSkill_OnDoHit` | **Confirmed** | type_info string |
| Slot = vtbl+0x2C | **Confirmed** | `009d15f0 - 009d15c4 = 0x2C` |
| Enqueue list `world+0xe4ec` | **Confirmed** | `mov ecx,[ebp+0xe4ec]` |
| Owner gate `+0x18` | **Confirmed** | `cmp [esi+0x18],0` + base attach dual |
| Product method English "Execute" | **Inferred** | family slot role; open demangle |
| Param product names beyond base map | **Probable** | via sealed base ctor |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog | Yes |
| Index loop / sentinel | Yes |
| ResolveObjectTarget | Yes |
| new 0x6c0 + base ctor + vtbl | Yes |
| Enqueue+Start vs dtor(1) | Yes |
| ret 0x18 / return 1 | Yes |

---

## 5. Gaps / open

1. Product C++ method name for vtbl+0x2C (Execute is role-inferred).
2. Whether any caller relies on ignored ECX instance state.
3. Upper bound on `index` (char wrap) — image unbounded until sentinel.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
