# Review B (skeptical / adversarial): `aa_0061c590` CVOGHBSkill_XP_ApplyToTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061c590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-015) |
| **Counterpart** | `reviews/A_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs/callers. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is still anonymous / unknown class | **Falsified** — type_info **`.?AVCVOGHBSkill_XP@@`** via COL on vtbl `009d119c` |
| 2 | Function is a **constructor** of XP HB | **Falsified** — constructs *other* objects; does not `mov [this], vtbl` on an inbound this |
| 3 | Function is OnHeartBeat / tick | **Falsified** — no tick reschedule core; sibling +0x0C `0061c940` owns that shape |
| 4 | Decompiler 3-arg Resolve is complete | **Falsified as complete** — bytes load **ECX=`[world+0xe4e8]`** before call; matches sealed Resolve thiscall |
| 5 | `nPeriodMs` write is SetPeriodAndCounter | **Falsified merge** — blob`+0x1c` → HB **`+0x08`** then separate `SetPeriodAndCounter(-1000,true)` on **`+0x0C/+0x10`** |
| 6 | Multiple direct CALL sites | **Falsified** — callers empty; sole xref DATA vtbl+0x2C |
| 7 | Object size unknown / 0x6d0 like some skill HBs | **Falsified** — `operator_new(0x6c0)` only |
| 8 | Always returns failure / void | **Falsified** — epilogue `mov eax,1` / `ret 0x18` |
| 9 | Invented product method English is Confirmed | **Survives as Inferred only** — class Confirmed; method role Inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class identity | **High** | Wrong skill-type port |
| Multi-target arm CF | **High** | Miss fan-out HB list |
| Resolve ctx offset +0xe4e8 | **High** | Null resolves / wrong table |
| HB list +0xe4ec | **High** | Actions never tick |
| Method English | Medium | Naming only |
| Virtual this usage | Low / open | ABI when hooked from C++ |

---

## 3. Cross-check against raw + bytes

```
; loop index * 0x10 + param_4
; sentinel -1/-1/mode0 → eax=1, ret 0x18
mov ecx, [ebx+0xe4e8]          ; resolve ctx (world)
call CVOGReaction_ResolveObjectTarget
push 0x6c0 / operator_new
mov ecx, esi
call CVOGHBSkillBase_ctor      ; 005788d0
mov dword [esi], 009d119c      ; XP vtbl
mov [esi+8], [skillBlob+0x1c]
SetPeriodAndCounter(esi, -1000, 1)
; owner? Enqueue([ebx+0xe4ec]) + Start : vtbl[0](1)
```

Clean must **not**:
- treat unit as Virus/SpawnEntities ctor,
- drop resolve this,
- merge +0x08 pulse with −1000 period pair,
- invent CALL-graph parents beyond vtbl DATA.

---

## 4. Surviving contract for AutoCore

```csharp
// Client skill residual — XP multi-target arm
foreach (var row in tfidRowsUntilSentinel) {
  var target = ResolveObjectTarget(world.ResolveCtxAtE4E8, row.Global, row.Lo, row.Hi);
  if (target == null) continue;
  var hb = new CVOGHBSkill_XP(); // retail size 0x6c0
  // base CVOGHBSkillBase_ctor(source, skillBlob, world, target, tfid16, arg7)
  // vtbl = XP; pulse = skillBlob.periodField; SetPeriod(-1000, true)
  if (hb.Owner != null) world.HbListAtE4EC.Enqueue(hb).Start();
  else hb.Delete(1);
}
// returns 1
```

Server ports that reimplement XP grant without client HB list may skip Enqueue/Start but must preserve **per-target resolve + validate/attach polarity**.

---

## 5. Open questions

1. PDB method name for vtbl+0x2C.
2. Who builds the row table (reaction target gather residual).
3. Null-`operator_new` path is retail UB — do not “fix” in exact ports without evidence.
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
