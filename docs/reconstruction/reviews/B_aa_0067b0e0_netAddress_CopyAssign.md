# Review B (skeptical / adversarial): `aa_0067b0e0` netAddress_CopyAssign

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b0e0` |
| **VA** | `0x0067b0e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Agent** | W25-P OWN-ONLY |
| **Counterpart** | `reviews/A_aa_0067b0e0_netAddress_CopyAssign.md` |
| **Verdict** | **accept-with-gaps** on CF; **reject** inventing non-POD or product English |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | Deep copy / heap alloc / refcount | **Falsified** — four stores only |
| 2 | `memcpy` with size arg / runtime length | **Falsified** — hard-coded 16 B via 4 dwords |
| 3 | Self-assign guard (`if this==src`) | **Falsified** — no compare |
| 4 | `__cdecl` / no stack cleanup | **Falsified** — `ret 4` thiscall |
| 5 | ECX is source (not dest) | **Falsified** — `mov eax,ecx` then store via EDX=dest; stack is src |
| 6 | Product name sealed as `TNL::Address` | **Survives as open** — role High only |
| 7 | Returns dest in EAX | **Falsified** — no return-value setup; void |
| 8 | Overwrites only 12 B (3 dwords) | **Falsified** — fourth store at `+0xC` present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level 4-dword copy + ret 4 | **Confirmed** | Low |
| dest=this / src=stack | **Confirmed** | Wrong ABI on port |
| Address POD 16 B | **High** | Mis-size if type grows (no evidence) |
| Product class name | **Open** | Docs naming only |
| Overlapping-buffer safety | **N/A** | dword-wise self-copy is well-defined |

---

## 3. Surviving contract for AutoCore

```text
// Native VA 0x0067b0e0 — Address POD copy-assign
//
// void Address_CopyAssign(Address *dest /* this */, const Address *src)
// {
//   dest->dwords[0..3] = src->dwords[0..3];  // 16 bytes
// }
// // thiscall; ret 4
//
// Port: memcpy(dest, src, 16) or struct assignment of a 16-byte POD.
// Do not invent refcounting, heap, or vtbl work.
```

**Port rules:**

1. **Do not** treat as string/BSTR copy.
2. **Do not** trust parent-seed name `Named_CalleeOf_…EncryptAndPrepare…` as role.
3. Pair with ctor `0067b070`, dtor `0067b110`, assign `0067b120` (owned elsewhere).

---

## 4. Open questions

1. Product/PDB class name.
2. Whether any call site uses non-16B object as this (no evidence in body).

**Verdict:** **accept-with-gaps** — adversarial pass does not overturn POD copy seal; naming gap only.
