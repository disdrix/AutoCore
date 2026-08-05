# Review B (skeptical / adversarial): `aa_006295f0` Phys_IslandHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006295f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-J) |
| **Counterpart** | `reviews/A_aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` |
| **Scratch** | `tmp/a_006295f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is host **attach** (`006291e0`) | **Falsified** — no object arg; only field init; callers attach *after* this |
| 2 | This is manager attach-register (`0055e760`) | **Falsified** — that is the caller that allocates then invokes this |
| 3 | ECX is the manager | **Falsified** — call site `MOV ECX, host`; manager is stack; written to `host+0x20` |
| 4 | Function has callees / allocates | **Falsified** — zero callees; arena alloc is caller's responsibility |
| 5 | Plain `ret` / cdecl | **Falsified** — epilogue `C2 04 00` |
| 6 | Nearby rdata strings prove Havok type name | **Overstated** — `StExamine` / `St3AxisSweep` sit after vtbl; not sealed RTTI for this class |
| 7 | Product name is retail | **Overstated** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor / field-init role | **High** | Uninitialized host / wrong vtbl |
| thiscall + ret 4 | **High** | ABI break |
| manager at +0x20 | **High** | Host orphaned from manager |
| List sentinel pattern | **High** | Later grow/free mismatch with dtor `006296c0` |
| Product class English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
MOV EAX, ECX          ; host
MOV EDX, [ESP+4]      ; manager
... stores ...
MOV [EAX+20], EDX
MOV dword [EAX], 009e331c
MOV dword [EAX+1c], 009e3310
... list inits ...
POP EDI
RET 4
```

Live 2026-07-29 decompile ≡ raw 2026-07-23 body. Sibling `006296c0` installs same primary vtbl then frees list slots — consistent ctor/dtor pair.

---

## 4. Surviving contract for AutoCore

```
// After arena.alloc(0xa8, tag 0x2d) and sizeword host+4 = 0xa8:
Phys_IslandHost_Ctor_Inferred(host, manager);
// Then: host+0x24 = manager.hostCount; Host_Attach(host, obj); push host list.
// Must preserve: vtbls, manager@+0x20, flags, list sentinels, ret 4.
// Do not substitute attach (006291e0) or attach-register (0055e760).
```

---

## 5. Verdict

Adversarial pass **confirms** A: pure ctor ABI/layout sealed; product name residual only → **accept**.
