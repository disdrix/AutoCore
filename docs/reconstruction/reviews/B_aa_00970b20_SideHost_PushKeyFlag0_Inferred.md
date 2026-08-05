# Review B (skeptical / adversarial): `aa_00970b20` SideHost_PushKeyFlag0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-N) |
| **Counterpart** | `reviews/A_aa_00970b20_SideHost_PushKeyFlag0_Inferred.md` |
| **Scratch** | `tmp/a_00970b20.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler void / no-args is complete | **Falsified** — `C2 04 00` RET 4; ECX key; stack host |
| 2 | Flag is runtime variable | **Falsified** — imm **`6A 00`** only |
| 3 | Container is host itself | **Falsified** — **`ADD EDI, 0xAC`** before push |
| 4 | thiscall ECX = host | **Falsified** — call sites push host and load key into ECX |
| 5 | Function is log string helper | **Nuanced** — pushes `{u32,u8}` into locked vector; not a string print |
| 6 | Product name retail | **Overstated** — inferred only |
| 7 | Same as flag1 twin | **Nuanced** — bit-twin except flag imm |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX key + stack host + RET 4 | **High** | Wrong object / stack tear |
| host+0xAC vector | **High** | Corrupt wrong field |
| flag = 0 | **High** | Event kind swap with twin |
| Nested = locked U32U8 push | **High** | Wrong POD width |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | CS races in nested |

---

## 3. Cross-check against raw + bytes

```
raw scaffold decompile:
  FUN_0043e8f0(); FUN_0043e7f0();   // incomplete surface

bytes (54 B full seal):
  83 EC 08  8B 11  56 57  6A 00  51 ...
  E8 … → 0043e8f0
  8B 7C 24 1C  83 C4 08  50  81 C7 AC 00 00 00
  E8 … → 0043e7f0
  5F 5E  83 C4 08  C2 04 00

call sites:
  0075e2d0: push [esi+0x6c]; mov ecx, local; call 00970b20
  00971030: push this; mov ecx, arg; call 00970b20
```

Live decompile 2026-07-29 still omits ABI; seal rests on `read_memory` + call-site bytes. Nested push free sealed W32-N.

---

## 4. Residual attacks left open

- Exact product type of key holder (resource*, map node field*, int*).
- Whether flag 0 means “remove/evict” vs other domain English.
- Full dual of adapter `0043e8f0` (not owned).

None overturn the structural seal → **accept-with-gaps**.
