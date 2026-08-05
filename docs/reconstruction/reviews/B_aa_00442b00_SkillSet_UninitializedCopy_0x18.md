# Review B (skeptical / adversarial): `aa_00442b00` SkillSet_UninitializedCopy_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00442b00_SkillSet_UninitializedCopy_0x18.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is `SkillSet_GetEntryCount` | Body is a copy loop; real GetEntryCount is thin `0x00402d80` | **Falsified** identity claim |
| 2 | Decompiler `__fastcall(begin,end)` is full ABI | Missing dest in EAX and return dest end | **Over-narrow** display |
| 3 | Element size is 24 bytes | `add +0x18`, parents `/0x18` and `new(n*0x18)` | **Survives** |
| 4 | Runs constructors per element | Only MOV stores; no CALL in body | **Falsified** ctor-loop claim |
| 5 | Void return | Parents assign return to vector end pointer | **Falsified** void — EAX is dest end |
| 6 | Name `UninitializedCopy` wrong | MSVC vector reallocate pattern + POD copy | **Survives** (role name) |
| 7 | Many non-skill callers | Ghidra xrefs **8** in **2** SkillSet bulk parents only | **Only those** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride / copy CF | **High** | Corrupt skill vector memory |
| ABI EAX/ECX/EDX | **High** | Wrong ports |
| Return dest end | **High** | Vector end pointer wrong after insert |
| SkillSet-only use | **High** | Missed alternate call sites (none found) |
| Entry field names | **Low** | Docs only |

---

## 3. Cross-check against raw / bytes

```
raw: for (p1!=p2; p1+=6) if (eax) copy 6 dwords; eax+=6
bytes: cmp ecx,edx; jz ret; loop copy; add ecx/eax,0x18; jnz; ret
```

Clean ≡ raw ≡ bytes. No modernization of CF.

---

## 4. Surviving contract for AutoCore

```csharp
// POD only — no per-element ctor
static unsafe byte* UninitializedCopy0x18(byte* dest, byte* begin, byte* end)
{
    while (begin != end)
    {
        if (dest != null)
            Buffer.MemoryCopy(begin, dest, 0x18, 0x18);
        begin += 0x18;
        dest += 0x18;
    }
    return dest;
}
```

**Port traps to reject:**

- Treating as GetEntryCount or count helper.
- Assuming thiscall ECX=this.
- Ignoring EAX dest / return end.
- Invoking C++ constructors for the 0x18 blob.

---

## 5. Residual gaps (do not block seal)

1. Entry typedef field map.  
2. Live differential.  
3. `0x00442b40` sibling (out of ownership).

---

## Verdict

**accept** — adversarial review cannot break the 0x18 POD range-copy kernel. Main falsifications are “this is GetEntryCount” and “ABI is only ECX/EDX void.”
