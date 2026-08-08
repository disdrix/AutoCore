# Review B (skeptical / adversarial): `aa_0061c940` CVOGHBSkill_XP_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061c940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-004) |
| **Counterpart** | `reviews/A_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs/callers + `get_function_by_address`. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Still anonymous / unknown class | **Falsified** — type_info **`.?AVCVOGHBSkill_XP@@`** via COL on vtbl `009d119c` |
| 2 | This is the multi-target **ApplyToTargetList** arm (`0061c590`) | **Falsified** — different body; no TFID row walk; vtbl **+0x0C** not +0x2C; alloc **0x6d0** not 0x6c0 |
| 3 | This constructs `CVOGHBSkill_XP` itself | **Falsified** — constructs **XPAdder** via `00650f50`; does not install XP vtbl on inbound this |
| 4 | Function is a constructor | **Falsified** — virtual OnHB shape; ends in RescheduleStatus; no `mov [this], vtbl` |
| 5 | `character+0xcb0` is a boolean flag only | **Falsified as complete** — bytes load pointer into ECX for `FUN_00574760` thiscall |
| 6 | Decompiler free-fn `FUN_00650f50(...)` is complete ABI | **Falsified as complete** — bytes `mov ecx,eax` before call; sealed thiscall ctor |
| 7 | Multiple direct CALL parents | **Falsified** — callers empty; sole xref DATA vtbl+0x0C |
| 8 | Alloc size is XP HB `0x6c0` | **Falsified** — only `push 0x6D0` |
| 9 | SharedOnHB `0061b6f0` body / heat-HP cascade | **Falsified** — no shared pulse cascade; only RescheduleStatus tail |
| 10 | Invented product method English is Confirmed | **Survives as Inferred only** — class Confirmed; OnHeartBeat role Inferred |
| 11 | Runtime Confirmed without Launcher | **Falsified** — Terminal false; not claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class identity | **High** | Wrong skill-type port |
| Personal / multi CF split | **High** | Miss convoy fan-out |
| XPAdder size 0x6d0 + ctor | **High** | Wrong subclass / size |
| Enqueue list +0xe4ec | **High** | Actions never tick |
| Slot helper 4-bound | **High** | Under/over spawn |
| Method English OnHeartBeat | Medium | Naming only |
| `+0xcb0` product noun | Medium | Docs only |
| Runtime | **Open** | No live proof |

---

## 3. Cross-check against raw + bytes

```
; prolog SEH LAB_009a87bb
mov esi, ecx                    ; this = CVOGHBSkill_XP
mov eax, [esi+0x18]
; RTDynamicCast → CVOGCharacter
mov ebp, [eax+0xcb0]            ; slot table host (or null)
test ebp, ebp
jz  personal_arm

; multi arm:
xor ebx, ebx
loop:
  mov ecx, ebp
  push ebx
  call FUN_00574760             ; thiscall table get
  test eax, eax / jz next
  push 0x6d0 / operator_new
  mov ecx, eax
  call FUN_00650f50             ; XPAdder_ctor thiscall
  ; pOwner? Enqueue([world+0xe4ec])+Start : vtbl[0](1)
  inc ebx / cmp ebx,4 / jl loop

personal_arm:
  movss xmm0, [esi+0x104]
  ucomiss xmm0, [g_flZero]
  ; if != 0: same new(0x6d0)+XPAdder target=source

push pOut / mov ecx, esi
call Skill_HB_RescheduleStatus  ; 005787a0
ret 4
```

Clean must **not**:
- merge with ApplyToTargetList `0061c590` (0x6c0 XP spawn),
- treat XPAdder ctor as free function without ECX,
- invent CALL-graph parents beyond vtbl DATA,
- claim SharedOnHB effect cascade,
- claim Runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Client skill residual — XP specialized OnHeartBeat
var character = DynamicCastCharacter(hb.SourceAt18);
var slotTable = character.FieldAtCb0; // multi-target host or null

if (slotTable == null) {
  if (hb.FloatAt104 != 0f) {
    var adder = new CVOGHBSkill_XPAdder(); // retail size 0x6d0
    // ctor(source, skillBlob, world, target=source, tfid, arg7)
    AcceptEnqueueOrDelete(world.HbListAtE4EC, adder);
  }
} else {
  for (int i = 0; i < 4; i++) {
    var slot = GetSlot(slotTable, i); // FUN_00574760
    if (slot == null) continue;
    var target = MiAdjust(slot);
    var adder = new CVOGHBSkill_XPAdder(... target ...);
    AcceptEnqueueOrDelete(world.HbListAtE4EC, adder);
  }
}
return Skill_HB_RescheduleStatus(hb, pOutStatus);
```

Server ports that reimplement XP grant without client HB list may skip Enqueue/Start but must preserve **personal residual gate + 4-slot fan-out + accept polarity**.

---

## 5. Open questions

1. PDB method name for vtbl+0x0C.
2. Who installs `character+0xcb0` (convoy join residual).
3. Null-`operator_new` path is retail UB — do not "fix" without evidence.
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
