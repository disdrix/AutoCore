# Review B (skeptical / adversarial): `aa_0056a680` Item_GetCycleTimeMs_Scaled_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a680` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-L) |
| **Counterpart** | `reviews/A_aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x0056a680` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Returns float seconds | callers cast to float then `* g_flMsToSeconds`; body returns int / 500 | **Falsified** — **integer ms** |
| 2 | Always scales | flag≠0 or scale==1 or null related → raw `+0xD0` | **Falsified** — **conditional scale** |
| 3 | Floor applies to raw path | floor only inside scaled arm after `scale != 1` | **Falsified as global floor** — raw can be &lt;500 |
| 4 | Comparison uses same call as return | cmp uses local ±bias+trunc; return uses `FUN_0040dab0` | **Both sealed** — same bias constant |
| 5 | `+0xD0` is HP/armor | DPS UI + tac-arc ms conversion + setter min 1 | **Falsified as HP** — **cycle ms** |
| 6 | stdcall void | `ret 4` + EAX int | **Falsified** |
| 7 | Clean invents proven PDB name | no product string in body | **Open English** — `_Inferred` |
| 8 | Three-rep diverges | live ≡ raw ≡ arm bytes | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ms base + optional scale + 500 floor | **High** | wrong DPS / fire cadence |
| thiscall ret 4 | **High** | stack corruption |
| Product type / `+0x1E8` name | **Inferred** | doc-only mislabel |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw:
  if flag==0 && related && blob && scale!=1:
    product = scale * base; if (int)(±bias) > 500: return Round(product); return 500
  return base

bytes:
  cmp [esp+8],0 / jnz raw
  load +0xB0 / test / jz raw
  vtbl+0x214 / ucomiss g_flOne
  mulss / ± 0x00aaa6d0 / cmp 500 / call 0040dab0 / ret 4
  mov eax,500 / ret 4
  mov eax,[esi+0xD0] / ret 4
```

**No conflict** on owned CF. English for types open.

---

## 4. Surviving contract for AutoCore

```csharp
// Item_GetCycleTimeMs_Scaled @ 0x0056a680
// retail: thiscall; char skipScale; ret 4; EAX = ms

int GetCycleTimeMs(Item self, bool skipScale)
{
  if (!skipScale) {
    var related = self.RelatedAtB0(); // MI +0xB0
    var blob = related?.Vfunc214();
    float scale = blob?.FloatAt1E8 ?? 1f;
    if (blob != null && scale != 1f) {
      float product = scale * self.CycleMs; // +0xD0
      if (RoundTowardNearest(product) /* bias 0.5001 */ > 500)
        return RoundTowardNearest(product);
      return 500;
    }
  }
  return self.CycleMs;
}
```

Port rules:

- Keep **500 floor only on non-identity scale path**.
- Use shared **±0.5001** round helper for return (`FUN_0040dab0` semantics).
- Treat unit as **milliseconds** for DPS: `dps = damage / (ms * 0.001)`.
