# Review B (skeptical / adversarial): `stoChunkWriter_WriteI32` @ `0x00439870`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00439870_stoChunkWriter_WriteI32.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory`, call-site context; no `disassemble_bytes` |
| **Verdict** | **accept** on CF / ABI / mode split; **accept-with-gaps** only on untyped stream iface |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` / ECX = writer | Body never uses ECX as writer; ESI holds writer; text path `mov eax,esi` for formatted helper | **Falsified as thiscall** |
| 2 | Format is `"%d"` or `"%u"` | DAT is `"%i"`; sibling is `"%u"` @ different VA | **Falsified** |
| 3 | Text path does not force a newline | After format: `mov [esi+0x20],0` + write `"\r\n"` | **Falsified** — always ends line |
| 4 | Binary path writes host-endian via printf | Binary is raw 4-byte `vtbl+0x18` of stack local | **Falsified as printf** |
| 5 | Returns the value written | Returns `status` at `+0x04` | **Falsified** |
| 6 | `Named_CalleeOf_Named_effEffect` is product name | Only parent-seed alias; role is chunk int write | **Falsified as product** |
| 7 | Mode nonzero always means mode==1 | Body tests `==0` vs else; BeginChunk same | **Nuanced** — product is 0/1; any nonzero takes text path |
| 8 | WriteFormatted receives writer on stack | Helper ABI is EAX writer (dual-sealed) | **Falsified as stack-this** |
| 9 | Clean is a drop-in portable API | Still register-shaped scaffold | **Scaffold** for rehost |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Binary 4-byte raw write | **High** | Corrupt chunk payload size/fields |
| Text `"%i"` + CRLF | **High** | Wrong text dumps / parse tools |
| ESI/EAX register ABI | **High** | Silent wrong writer/value at call sites |
| Status OR return | **High** | Lost I/O errors |
| Signed vs unsigned twin | **High** | Sign-extend display bugs if swapped |
| Stream vtbl method full type | **Medium** | Wrong rehost of write callback |

---

## 3. Surviving contract for AutoCore

```
stoChunkWriter_WriteI32(writer /*ESI*/, pValue /*EAX → int32*/):
  v = *pValue
  if writer.mode == 0:                    // +0x1c
    writer.status |= stream.write(&v, 4)  // vtbl+0x18
  else:
    writer.status |= WriteFormatted(writer, "%i", v)  // helper EAX=writer
    writer.textColumn = 0                 // +0x20
    writer.status |= stream.write("\r\n", 2)
  return writer.status                    // +0x04
```

Sibling: `0x00439810` identical with `"%u"` → `stoChunkWriter_WriteU32` (not owned this pass).

---

## 4. Open questions

1. Full stream interface IID / method names for `vtbl+0x18`.
2. Golden binary/text dumps for values 0, −1, INT_MAX.
3. Whether any caller expects mid-line integer tokens (this helper always CRLFs in text mode).

**Verdict:** **accept** — CF, strings, mode split, and register ABI are sealed; safe as the signed int writer for stoChunk serializers.
