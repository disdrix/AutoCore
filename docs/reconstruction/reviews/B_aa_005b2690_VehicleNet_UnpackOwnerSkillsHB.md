# Review B (skeptical / adversarial): `aa_005b2690` VehicleNet_UnpackOwnerSkillsHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2690` |
| **VA** | `0x005b2690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2690_VehicleNet_UnpackOwnerSkillsHB.md` |
| **Evidence** | Live decompile + callees; pack twin; parent UnpackGhost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same as identity unpack `0x005b1360` | **Falsified** | Counted payload loop + malloc + ByteBuffer |
| 2 | Parses skill opcodes inline | **Falsified** | Opaque `size` + bulk `FUN_005b1570` only |
| 3 | Zero count still inserts | **Falsified** | Early exit when count==0 |
| 4 | Leaks prior ByteBuffer on replace without refcount | **Falsified** | Refcount-- + vtbl+8 free path before attach |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Count + size + bulk payload | **High** | Skills desync |
| Separation from identity block | **High** | Wrong ghost section |
| Container insert semantics | **Medium** | List vs map ownership |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
UnpackOwnerSkillsHB(stream):
  count = readU8()
  for i in 0..count-1:
    size = readU16()
    buf = malloc(size); readBulk(stream, buf, size)
    node = wrap ByteBuffer(buf,size,owns=1); node.bitCursorSeed = 0x40
    insert(node)
```

**Verdict:** **accept-with-gaps**
