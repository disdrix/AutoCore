# Review B (skeptical / adversarial): `aa_004c2f20` Skill_ApplyBoundStatusMotionIfPresent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2f20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c2f20_Skill_ApplyBoundStatusMotionIfPresent_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` body + caller site bytes. No `disassemble_bytes`. Own VA `0x004c2f20` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `__fastcall` single-arg is ABI truth | Bytes: `RET 4` + tail needs stack skillId for `FUN_005d0d60(this, param_2)` | **Falsified** — **thiscall + 1 stack dword** |
| 2 | `FUN_005d0d60()` is called with no args | Machine **JMP** with ECX rewritten; callee prologue uses ECX as this and reads stack | **Falsified** as zero-arg |
| 3 | Unit is a CALL with local return always | `E9` JMP on non-null path | **Falsified** — **true tail** |
| 4 | `this` is the skill object | Caller moves **EAX from caster vtbl+0x214** into ECX | **Falsified** — **binding object**, not skill* |
| 5 | `this` is the caster entity | Same — intermediate return of vtbl+0x214 | **Falsified** as caster* |
| 6 | Offset +0x1FC is gear mult / friction setup (physics docs) | Physics uses +0x1FC on **other** object families | **Falsified conflation** — same numeric off, different type |
| 7 | Multiple callers / general utility | `get_xrefs_to` → sole `0x00553936` | **Falsified breadth** — **one** skill apply site |
| 8 | Function returns useful pointer (decomp assigns to piVar5) | Body never writes EAX product; void epilogue | **Falsified as value-return** — caller assignment is decomp noise |
| 9 | Three-rep diverges on CF | raw ≡ live decomp CF; bytes match gate | **Falsified** conflict |
| 10 | Body does handbrake / impulse itself | No such ops; only gate + JMP | **Falsified** — **wrapper only** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate on +0x1FC + tail JMP | **High** | Miss optional path entirely |
| thiscall + RET 4 + skillId stack | **High** | Stack smash / wrong formal |
| Sole caller ApplyEffects | **High** | Wrong system placement |
| skillId = skill+0x5FC | **High** | Wrong table key into 005d0d60 |
| boundObj type English | **Medium** | Doc-only |
| +0x1FC controller type | **Medium** | Wrong layout port |
| Full 005d0d60 semantics | **Open** (sibling) | Incomplete status-motion port |
| Runtime / bit-exact | **Open** | Shipping fidelity |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  if (*(int*)(param_1 + 0x1fc) != 0) { FUN_005d0d60(); return; }
  return;

bytes:
  mov ecx,[ecx+0x1fc]; test ecx,ecx; jz ret4; jmp FUN_005d0d60; ret 4

caller (0x00553920):
  push [skill+0x5fc]; call caster.vtbl+0x214; mov ecx,eax; call 0x004c2f20
```

**No CF conflict.** ABI must be read from **bytes**, not decompiler signature display (`undefined FUN_004c2f20(void)` is stale).

---

## 4. Surviving contract for AutoCore

```csharp
// Skill_ApplyBoundStatusMotionIfPresent_Inferred @ 0x004c2f20
// this = result of caster.Vtbl214(skillId)
// stack: int skillId; RET 4

void ApplyBoundStatusMotionIfPresent(object boundObj, int skillId)
{
    var ctl = boundObj.PtrAt(0x1FC);
    if (ctl != null)
        FUN_005d0d60(ctl, skillId); // status/motion table apply (sibling)
}
```

Port notes:
- Call only from apply-effects when vtbl+0x214 probe non-null.
- Do **not** invent multi-target walks or combat events here.
- Do **not** treat +0x1FC as vehicle gear mult from physics docs.

---

## 5. Verdict

**accept-with-gaps** — adversarial pass strengthens ABI over decompiler and seals sole integration point; type English and callee dual remain open.
