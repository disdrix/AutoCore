# Review B (skeptical / adversarial): `CVOGRoadNode_ParseWidthFromTexName` @ `0x005e6c40`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e6c40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005e6c40_CVOGRoadNode_ParseWidthFromTexName.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Width from mesh AABB | Falsified — name suffix parse |
| 2 | Default 1.0 | Falsified — DAT_00a110d8 (~10) |
| 3 | Uses first '_' token | Falsified — last '_' via strrchr |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Last-_ atof → +0x164 | High | Road width wrong |
| Default on missing suffix | High | Too narrow/wide |
| Min clamp constant | Medium | Zero-width roads |

---

## 3. Cross-check against raw

```
copy name; p=strrchr('_'); if !p: default+log; else atof+clamp → +0x164.
```

---

## 4. Surviving contract for AutoCore

```
ParseWidthFromTexName(node, texName):
  width = atof(after last '_') or default 10
  clamp min; node.width(+0x164) = width
  content pipeline naming convention critical
```

---

## 5. Open questions

1. Confirm DAT_00a110d8 == 10.0f and min constant.

**Verdict:** **accept**
