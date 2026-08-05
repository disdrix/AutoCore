# Review B (skeptical / adversarial): `aa_00799820` XmlAttr_FetchParseLong_StoreByteIfOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-G) |
| **Counterpart** | `reviews/A_aa_00799820_XmlAttr_FetchParseLong_StoreByteIfOk.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This writes a full 32-bit long to `*out` | **Falsified** — bytes store single byte from stack temp; decompile `*param_3 = local_4[0]` |
| 2 | This is the same as `00799460` (no wrapper) | **Falsified** — separate 44 B body; always calls `00799460` then maybe store |
| 3 | Failed fetch zeroes the out byte | **Falsified** — `jz` skips store; out unchanged |
| 4 | Sole caller is UseItem_SerializeXml | **Falsified** — ≥16 xrefs / multiple mission deserializers |
| 5 | Return value is success char | **Falsified** — void wrapper; AL tested then discarded |
| 6 | Clean invents extra validation | **Falsified** — clean is fetch + optional byte store only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Conditional byte store CF | **High** | Wrong field width in mission structs |
| No-write on fail | **High** | Clobbering pre-init slot defaults |
| Shared helper (many sites) | **High** | Missing ports of objective attrs |
| Truncation semantics for values &gt;255 | Medium | Silent wrap if large ints ever passed |
| Product attr names | Open | Per-caller only |

---

## 3. Cross-check against raw + bytes

```
push local
call XmlAttr_FetchAndParseLong(node, name, &tmp, base)  // add esp,0x10
test al,al
jz done
*outByte = (uint8_t)tmp
done: ret
```

Clean must **not** invent full-long stores, default-on-failure, or string compares (attr names are caller args).

---

## 4. Surviving contract for AutoCore

```csharp
// Port of XmlAttr_FetchParseLong_StoreByteIfOk
static void XmlAttr_FetchParseLong_StoreByteIfOk(
    XmlNode node, string attr, ref byte outByte, int bas = 10)
{
    if (XmlAttr_FetchAndParseLong(node, attr, out long tmp, bas))
        outByte = unchecked((byte)tmp);
    // else leave outByte unchanged
}
```

Example parent: Collect objective `slot` attribute → `requirement.Slot` at `+0x08`.

---

## 5. Open questions

1. Full attr-name × base matrix across all xrefs.
2. Whether any site intentionally depends on `(byte)long` truncation for values outside 0–255.
3. Runtime golden on missing attr (out preserved).

**Verdict:** **accept-with-gaps**
