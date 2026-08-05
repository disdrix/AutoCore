# Review B (skeptical / adversarial): `aa_0096f510` RefCountedPtr3Flags_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-H) |
| **Counterpart** | `reviews/A_aa_0096f510_RefCountedPtr3Flags_Dtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `FUN_0096efd0` (RefCountedPtr dtor) | **Falsified** — efd0 uses ref@**+8**, iface@**+4**, clears handle, SEH; this is ref@**+4**, vtbl@**+0**, no clear, 18 B leaf |
| 2 | Clears `*handle` after release | **Falsified** — `mov ecx,[ecx]` destroys handle address; no store back |
| 3 | `FF 60 08` is a multi-way jumptable | **Falsified** — single indirect **JMP** through vtbl[+8]; decompiler warning is noise |
| 4 | Only used by CVOGTacArc | **Falsified** — many Unwind@* + graphics hosts + vector DATA dtor slots |
| 5 | Scaffold `Named_CalleeOf_CVOGTacArc_dtor_helper_*` is product name | **Rejected** — parent-seed alias; role is generic 3Flags dtor |
| 6 | Touches flag bytes +4/+5/+6 | **Falsified** — only payload path; handle flags untouched |
| 7 | Peer ctor pairing is coincidence | **Rejected** — `_eh_vector_constructor_iterator_(…,8,…,0096f530,0096f510)` + adjacent VAs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null / dec / tail Release CF | **High** | Leaks / UAF |
| ECX handle / void / bare C3 | **High** | Wrong convention |
| Distinct from `0096efd0` | **High** | Merged release policies |
| Peer ctor 0096f530 | **High** | Wrong element size |
| Payload product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Body hex @ 0x0096f510 (18 B):
// 8B 09 | 85 C9 74 0B | 83 41 04 FF | 75 05 | 8B 01 FF 60 08 | C3

// Peer ctor @ 0x0096f530 (W35-G):
// 8B C1 33 C9 89 08 88 48 04 88 48 05 88 48 06 C3

// DATA: FUN_00457720 vector_ctor element size 8, dtor = this
// Live decompile 2026-08-04 ≡ raw 2026-07-23 CF
```

---

## 4. Surviving contract for AutoCore

```
// Port as RefCountedPtr3Flags dtor:
//   ECX = handle* (8-byte shell; only .ptr used)
//   if (payload = handle->ptr) {
//     if (--payload->refcount /*@+4*/ == 0)
//       tail_jump payload->vtbl[2]; // +8
//   }
//   // do NOT clear handle->ptr; do NOT touch flags
// Pair with RefCountedPtr3Flags_DefaultCtor (0096f530).
// Do NOT substitute RefCountedPtr dtor (0096efd0).
// Reject Named_CalleeOf_* scaffold aliases.
```

---

## 5. Verdict

Adversarial pass confirms A on bytes/ABI/layout/peer pairing and rejects scaffold/parent-only names. Residual product English → **accept-with-gaps**.
