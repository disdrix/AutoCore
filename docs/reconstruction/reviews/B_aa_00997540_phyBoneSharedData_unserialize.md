# Review B (skeptical / adversarial): `phyBoneSharedData_unserialize` @ `0x00997540`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00997540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00997540_phyBoneSharedData_unserialize.md` |
| **Verdict** | **accept-with-gaps** on tag/version/scale fork; **needs-more-evidence** on f32 array sizes + thiscall |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Log string names function phyBoneMaster → wrong unit | **Overstated risk** — path is phyBoneSharedData.cpp; string is legacy wording |
| 2 | v1 and v2 identical | **Falsified** — v1 forces scale ones; v2 reads third f32 array |
| 3 | Bind 4×4 is the bone transform | **Falsified by plate** — near-identity BIND, separate from hkQsTransform |
| 4 | Always has nested object at +0x80 | **Falsified** — only if FUN_0076a900 non-zero |
| 5 | Quaternion order xyzw sealed in body | **Overstated** — plate; arrays not expanded here |
| — | Runtime verified | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| BDAT tag + v1/v2 | High | Bone load fails / wrong assets |
| v1 unit scale force | High | Non-uniform rest pose wrong |
| Nested optional factory | Medium | Missing collision/BV link |
| thiscall param roles | Medium | Wrong Autocore signature |
| hkQsTransform math order | Medium (plate) | Skinning / root TF wrong |

---

## 3. Surviving contract for AutoCore

```
phyBoneSharedData_unserialize(out, reader) -> int:
  EnterChunkScope(reader)
  if tag != 0x42444154: log; leave; return -1
  if version == 1:
    read name → out+0x8
    readF32Array; readF32Array   // rot + translation
    read bind 4x4
    maybe nested → out+0x80
    out.scale = (1,1,1)
  else if version == 2:
    read name → out+0x8
    readF32Array x3              // rot + translation + scale
    read bind 4x4
    maybe nested → out+0x80
  else: log invalid version; return -1
  leave; return nested-status
```

---

## 4. Open questions

1. Exact f32 counts per readF32Array call.
2. Type of nested object at +0x80.
3. Confirm nesting under NOBP with sibling phyBone_unserialize.

**Verdict:** **accept-with-gaps** — solid BDAT version map for Autocore phy import.
