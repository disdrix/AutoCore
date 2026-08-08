# Review B (skeptical / adversarial): `aa_00409f30` StdVector_PodCopyElement_0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9I-B) |
| **Counterpart** | `reviews/A_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack thiscall ECX=this | **Falsified** — no ECX this; EAX dest + EDX src; callers set both regs |
| 2 | `void` means no args / dead code | **Falsified** — decomp void is display; live ABI is EAX/EDX |
| 3 | Copy 0xC / 12-byte twin | **Falsified** — imm count **10** dwords = **0x28** |
| 4 | ConstructN itself (loop) | **Falsified** — leaf only; ConstructN is `00409d40` |
| 5 | Always copies even on null dest | **Falsified** — `TEST EDI` / `JZ` skip |
| 6 | Non-POD ctor (vftable / deep copy) | **Falsified** — pure `REP MOVSD` |
| 7 | Same as 0x138 PodCopyConstruct | **Falsified** — different VA/size (`00408880` / 0x138) |
| 8 | Multi-arg stdcall | **Falsified** — bare `C3`, zero stack args |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 10-dword leaf copy | **Confirmed** | Wrong element size |
| EAX/EDX ABI | **Confirmed** | Stack corruption |
| Null dest no-op | **Confirmed** | Spurious write |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against ConstructN parent

```
// WQ9H-B sealed FUN_00409d40:
//   loop: PodCopy(EAX=dest, EDX=value); dest += 0x28
// This OWN unit is exactly that PodCopy leaf (10 dwords).
// Range twin FUN_0040a520: same call shape; advances both cursors +0x28.
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared POD element copy for stride 0x28:
//  - if (dest) memcpy(dest, src, 0x28) via 10 dwords
//  - ABI: EAX=dest, EDX=src, plain ret
//  - Pair with ConstructN 00409d40 / Ufill 00406e50 / push_back 00406220
// Do not merge with 12-byte or 0x138 POD leaves; not a construct-N loop.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/size. Product residual → **accept-with-gaps**.
