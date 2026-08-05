# Review B (skeptical / adversarial): `aa_006291e0` PhysHost_AttachObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006291e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-I) |
| **Counterpart** | `reviews/A_aa_006291e0_PhysHost_AttachObject_Inferred.md` |
| **Scratch** | `tmp/a_006291e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is AttachRegisterHost (`0055e760`) | **Falsified** — no manager logic / sticky / island create; pure host leaf; sole *callee* of AttachRegisterHost |
| 2 | This is host init (`006295f0`) | **Falsified** — pushes obj + notify; no manager field init |
| 3 | ECX is world object | **Falsified** — callers `MOV ECX,host`; stamps `obj+0x44=ECX` |
| 4 | Decompiler vcall this is host for both | **Falsified for first** — machine `MOV ECX,[obj+0x3c]` before `vtbl+0x14` |
| 5 | Grow is thiscall | **Falsified** — `ADD ESP,8` after `FUN_005b3370` |
| 6 | Plain `ret` / 0 stack | **Falsified** — `C2 04 00` |
| 7 | Multiple external callers | **Falsified** — 3 xrefs all inside `0055e760` |
| 8 | Product name is retail | **Overstated** — `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host-attach leaf role | **High** | Objects not on host list / wrong backlink |
| thiscall + ret 4 | **High** | ABI break |
| Vector + stamps | **High** | Index desync / use-after-free remove paths |
| Nested vcall this | **High** | Wrong object method / crash |
| Vfunc product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
MOV host,ECX; MOV obj,[ESP+…]
MOV [obj+0x44],host
LEA vec,[host+0x3c]
if size == (cap & 0x7fffffff): grow(vec,4) cdecl
data[size]=obj; size++; [obj+0x58]=size-1
MOV ECX,[obj+0x3c]; CALL [vtbl+0x14]
PUSH EAX; MOV ECX,host; CALL [host.vtbl+0x10]
RET 4
```

W29-T residual that nested dual of `006291e0` was open is closed here for CF/ABI; product vfunc names remain open.

---

## 4. Surviving contract for AutoCore

```
// After host selection in AttachRegisterHost:
PhysHost_AttachObject_Inferred(host, obj);
// Must preserve: obj+0x44 backlink, vector@host+0x3c push, obj+0x58 index,
// nested query then host notify, ret 4, grow cdecl.
// Do not call with manager as this — host only.
// Do not substitute BindLinks / Unbind / host init.
```

---

## 5. Verdict

Adversarial pass **confirms** A: leaf role, ABI, vector/stamps, vcall this sealed; product English open → **accept-with-gaps**.
