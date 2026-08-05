# Review B (skeptical / adversarial): `aa_0075d3c0` AssManager_EnsureAssPreloader_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d3c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-O) |
| **Counterpart** | `reviews/A_aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN(int)` / plain RET | **Partially false** — epilogue is **`RET 4`** (one stack arg); sealed by bytes `C2 04 00` |
| 2 | Always constructs preloader | **Falsified** — gated on `*(host+0x6c)==0` only |
| 3 | thiscall ECX=host | **Falsified** — stack formal (`MOV EBP,[ESP+…]`); callers push host |
| 4 | Seeds into pending +0x1c | **Falsified** — `ADD EDI,0xAC` on preloader; ring is **`+0xAC`** (W32-N locked U32U8) |
| 5 | Product method name in body | **Overstated** — no method string; host role from ctor/DAT_00d1f050 + AssManager_Sweep `+0x6c` secondary |
| 6 | Scaffold Client_InitInstance name | **Rejected** — not product evidence |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 4 + stack host | **High** | Stack smash |
| +0x6c AssPreloader slot | **High** | Wrong secondary host |
| Seed ring +0xAC PodU32U8 | **High** | Corrupt preloader ring |
| List host+8 key@+8 | **High** | Wrong seed keys |
| Product method English | **Inferred** | Naming only |
| Nested ctor dual | **Open** | Incomplete port |
| Runtime | **Open** | OOM / race |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if host+0x6c == 0:
    new(0x114); FUN_00970cf0 → +0x6c
    for list host+8: pack {node+8,1}; push locked pre+0xAC

bytes:
  83 7D 6C 00          cmp [ebp+0x6c],0
  68 14 01 00 00       push 0x114
  81 C7 AC 00 00 00    add edi, 0xAC
  C2 04 00             ret 4
```

Callers: `FUN_0075d470` post-zero `+0x6c`; `FUN_00934420` push `DAT_00d1f050` after "Preloading enabled".

---

## 4. Surviving contract for AutoCore

```
// AssManager ensure AssPreloader at host+0x6c:
//   stack host*; RET 4; void
//   If +0x6c live → no-op
//   Else new(0x114)+AssPreloader_Ctor (FUN_00970cf0); seed list host+8
//     keys as PodU32U8 {key,1} into preloader+0xAC (locked)
// Disable path (not this VA) deletes +0x6c via FUN_00971050/00971180.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/seed ring; product English + nested ctor residual → **accept-with-gaps**.
