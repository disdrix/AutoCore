# Review B (skeptical / adversarial): `aa_0055e760` WorldObj_AttachRegisterHost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-T) |
| **Counterpart** | `reviews/A_aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` |
| **Scratch** | `tmp/a_0055e760.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is bind-links (`0055fa40`) | **Falsified** — no link walk; only host attach + optional host create; callers always call `0055fa40` *after* this |
| 2 | This is enroll (`00560ec0`) | **Falsified** — enroll is a caller that also bumps refcounts / `0062a450`; this is nested attach only |
| 3 | ECX is the world object | **Falsified** — call sites `MOV ECX, manager`; `obj` is stack; stamps `obj+8=ECX` |
| 4 | Decompiler `FUN_006291e0(obj)` is complete | **Falsified as ABI** — machine sets ECX to host (`*(mgr+0x2c)` / new host / `list[0]`) before call |
| 5 | Always creates a new host | **Falsified** — sticky and non-empty non-island paths attach only |
| 6 | Plain `ret` / stdcall | **Falsified** — epilogue `C2 04 00` |
| 7 | Product name is retail | **Overstated** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Attach-register role | **High** | Wrong host ownership / missing mode-7 glue |
| thiscall + ret 4 | **High** | ABI break |
| Host this-pointer variants | **High** | Object bound to wrong island |
| Alloc size/tag 0xa8/0x2d | **High** | Arena corruption |
| Product flag English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH EBP; obj=[esp+8]; TEST [obj+0x40]
MOV ESI,ECX; MOV [obj+8],ESI
JZ not_sticky
  MOV ECX,[ESI+0x2c]; PUSH obj; CALL 006291e0; RET 4
CMP [ESI+0x23c],0 / alloc path / OR empty-list create
MOV ECX, first host; PUSH obj; CALL 006291e0; RET 4
```

Live 2026-07-29 ≡ raw stages; clean documents machine this. Three callers always manager ECX + obj stack.

---

## 4. Surviving contract for AutoCore

```
// Before bind-links on enroll / enter-mode-7 reattach / rehome phase 0:
WorldObj_AttachRegisterHost_Inferred(manager, obj);
// Must preserve: obj+8 stamp, sticky path via *(manager+0x2c),
// island/empty host create (0xa8/tag 0x2d), attach this=host, ret 4.
// Do not substitute BindLinks (0055fa40) or Unbind (0055fbf0).
```

---

## 5. Verdict

Adversarial pass **confirms** A: role/ABI/host-this sealed; decompiler residual documented → **accept**.
