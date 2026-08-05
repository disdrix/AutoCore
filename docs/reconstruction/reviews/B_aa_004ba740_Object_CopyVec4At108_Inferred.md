# Review B (skeptical / adversarial): `aa_004ba740` Object_CopyVec4At108_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba740` |
| **VA** | `0x004ba740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ba740_Object_CopyVec4At108_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **transforms** / rotates / normalizes the vector | Math helper habit | **Falsified** — pure dword loads/stores; no FP ops |
| 2 | Source is `this+0x90` or `+0x30` (common transform slots) | Sibling offset confusion | **Falsified** — `add ecx, 0x108` only |
| 3 | cdecl / stack `this` | Non-thiscall habit | **Falsified** — ECX base; `ret 4` |
| 4 | Copies only float3 (no W) | Float3 pack assumption | **Falsified** — fourth store `[edx+0xC]` |
| 5 | Writes into `this` (setter) | Direction flip | **Falsified** — loads from this+0x108, stores to out* |
| 6 | Exclusive “VOG_DEBUG_STOP helper” | Parent-seed alias | **Falsified as exclusive** — also FX host `004b7e50` and two other callers |
| 7 | Name `Object_CopyVec4At108` is string-proven | Symbol inflation | **Not sealed** — **Probable / `_Inferred`** |
| 8 | Field is definitely world position | Semantic leap | **Not sealed** — offset High; product role Tentative |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `ret 4` | **High** | ABI break |
| Source `+0x108..+0x114` | **High** | Wrong layout field |
| 4-dword copy leaf | **High** | Over-port math |
| float vs int interpretation | **Med** | Type doc only |
| Product English name | **Low–Med** | Doc only |
| Full caller English | **Low** | Miss non-FX consumers |

---

## 3. Cross-check against raw

```text
// raw aa_004ba740 ≡ live decompile ≡ bytes 2026-07-29
// thiscall ECX; out* = [esp+4]
out[0] = *(this + 0x108)
out[1] = *(this + 0x10c)
out[2] = *(this + 0x110)
out[3] = *(this + 0x114)
// ret 4; no callees
```

Clean scaffold `FUN_004ba740.cpp` ≡ raw outline.

---

## 4. Surviving contract for AutoCore

```
Object_CopyVec4At108_Inferred(this, out[4]):
  // __thiscall; pure leaf
  memcpy-style 16 bytes from this+0x108 → out
  // no normalize, no transform, no side effects on this

// Known consumers:
//   FUN_004b7e50 (FX host process list)
//   FUN_005cd3b0 (2 sites), FUN_005da0a0 (3 sites)
```

**Port tests that matter:**

* Exactly **16 bytes** from `this+0x108`.
* Must **not** invent math.
* Must use **thiscall** / one out pointer.
* Do not treat parent-seed `Named_VOG_DEBUG_STOP` alias as sole role.

---

## 5. Open questions

1. Product name of object type and field at `+0x108`.
2. Whether callers treat pack as XYZ+W float or mixed.
3. Runtime samples from known object instances.

**Verdict:** **accept-with-gaps** — attacks on math role, wrong offset, setter direction, exclusive-debug naming **fail**; remaining gaps are product field English / type interpretation only.
