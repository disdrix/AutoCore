# Review B (skeptical / adversarial): `aa_00409ed0` SkillSet_CopyBackward_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-054 OWN dual) |
| **Counterpart** | `reviews/A_aa_00409ed0_SkillSet_CopyBackward_0x18.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This **is** `SkillSet_GetEntryCount` | Body is reverse copy loop; real GetEntryCount is thin `0x00402d80` (`(end-begin)/0x18`) | **Falsified** identity claim |
| 2 | Scaffold `Named_CalleeOf_…` is a product name | Chain-of-caller only; zero strings; role is mem kernel | **Falsified** as canonical |
| 3 | Decompiler `__fastcall(ECX,EDX)` void is full ABI | Missing dest in EAX and return dest_begin; 5 call sites set EAX | **Over-narrow** display corrected |
| 4 | Element size is 24 bytes (`0x18`) | `SUB …,0x18` ×2 per iter; 6 dword stores; parents use `/0x18` and forward twin `00442b00` | **Survives** |
| 5 | This is forward `UninitializedCopy` | Walk is SUB not ADD; no `test eax,eax` null skip present in `00442b00` | **Falsified** merge |
| 6 | Runs constructors / virtual calls per element | Only MOV dword stores; **0** callees | **Falsified** ctor-loop claim |
| 7 | ECX = this (thiscall SkillSet method) | Call sites load range ends into ECX/EDX/EAX; no `this` object ops in body | **Falsified** thiscall |
| 8 | `RET 4` / stack args | Body ends `C3` plain RET; no stack pops of args | **Falsified** RET4 claim |
| 9 | Many non-skill callers | Ghidra xrefs **5** — all SkillSet insert/reallocate parents | **Only those** |
| 10 | Return void (EAX garbage) | Empty path leaves EAX=dest_end; loop leaves dest_begin — `copy_backward` return | **Falsified** void semantics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride / reverse CF | **High** | Corrupt skill vector on insert |
| ABI EAX/ECX/EDX + RET 0 | **High** | Wrong ports / stack smash |
| Return dest_begin | **High** | Callers that consume EAX miswired |
| SkillSet-only use (5 xrefs) | **High** | Missed alternate sites (none found) |
| Entry field English | **Low** | Docs only |
| Product demangle | **Tentative** | Name quality only |

---

## 3. Cross-check against raw / bytes

```
raw decompile: while (param_2 != param_1) { copy in_EAX[-6..-1] from param_1[-6..-1]; both -= 6 }
bytes: cmp edx,ecx; jz ret; push; sub ecx/eax,0x18; cmp; mov×12; jnz; pop×3; ret
```

Clean ≡ raw CF ≡ bytes direction/stride. No modernization of CF. Null-dest path **absent** (odd vs forward twin — **preserved**).

---

## 4. Surviving contract for AutoCore

```csharp
// POD only — no per-element ctor; reverse walk for overlap-safe shift
static unsafe byte* CopyBackward0x18(byte* destEnd, byte* srcEnd, byte* srcBegin)
{
    if (srcBegin == srcEnd)
        return destEnd;
    do
    {
        srcEnd -= 0x18;
        destEnd -= 0x18;
        Buffer.MemoryCopy(srcEnd, destEnd, 0x18, 0x18);
    } while (srcEnd != srcBegin);
    return destEnd; // destBegin
}
```

**Port traps to reject:**

- Treating as GetEntryCount or any count helper.
- Assuming thiscall `ECX=this`.
- Ignoring EAX dest / return begin.
- Merging with forward `UninitializedCopy` (wrong direction / null skip).
- Invoking C++ constructors for the 0x18 blob.
- Expecting `RET 4` stack cleanup.

---

## 5. Residual gaps (do not block seal)

1. Entry typedef field map.  
2. Live differential / runtime Confirmed.  
3. Parent insert duals (out of ownership).  
4. Exact MSVC demangle string.

---

## Verdict

**accept** — adversarial review cannot break the reverse 0x18 POD range-copy kernel. Main falsifications: GetEntryCount identity, Named_CalleeOf product name, thiscall, void/RET4, and forward-copy merge. CF/ABI/stride/callers sealed.
