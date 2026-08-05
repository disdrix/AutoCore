# Review B (skeptical / adversarial): `ClientSpecialEvent_Respawn_TeardownAirlift` / `FUN_00979290` @ `0x00979290`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/callers; residual product names open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is SetupAirlift (`00979310`) | **Falsified** — no CBID 0xadc / anim loads; only teardown path |
| 2 | Stack thiscall with ECX = event | **Falsified** — **EDI this**; no stack formals; plain `ret` |
| 3 | Always destroys ship geo object | **Falsified** — resolves TFID entity path; no `operator_delete` of ship |
| 4 | Clears latch only on success | **Falsified** — clear `+0x38` outside resolve-null check |
| 5 | `Vehicle_ActivateEnterWorld` is free function no-arg | **Partial trap** — decomp shows bare call; bytes load **ECX = resolved** |
| 6 | Camera restore is inside this VA | **Falsified** — camera is parent Update/dtor after/before call |
| 7 | Product vtbl name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + clear `+0x38` | **Confirmed** | Stuck airlift state |
| EDI ABI | **Confirmed** | Wrong this / crash |
| Resolve via `004bb010` | **Confirmed** | Wrong entity |
| ActivateEnterWorld ECX | **Confirmed** | Wrong vehicle re-enter |
| Teardown vs setup role | **High** | Double-setup fantasy |
| vtbl `+0x1bc` meaning | **Low** | wrong detach semantics in port docs |
| `+0x04` / `+0x68` names | **Tentative** | docs only |

---

## 3. Surviving contract for AutoCore

```
// EDI = ClientSpecialEvent_Respawn* this
TeardownAirlift():
  if this.flag_0x38 == 0: return
  obj = ResolveTfIdVtbl1d4(DAT_00b04830, &this.tfid_0x28)
  if obj:
    obj.MI.vtbl[+0x1bc](0)
    phys = obj+0x8
    phys.mode_0x28 = this.snapshot_0x68
    FUN_00560e90(phys)
    if this.flag_0x04 == 0:
      Vehicle_ActivateEnterWorld(obj)  // thiscall ECX=obj
  this.flag_0x38 = 0

// NOT SetupAirlift. NOT camera restore. NOT ship heap free.
// Server port: N/A client VFX; do not invent C2S from this VA.
```

---

## 4. Falsification notes

### 4.1 Setup/teardown swap

Setup dual allocates CBID `0xadc`, loads three `.anm`, sets cancel `+0x08`. This VA never touches those paths.

### 4.2 Decompiler ECX drop

`Vehicle_ActivateEnterWorld` and resolve both need ECX. Bytes restore both; ports following void decomp signatures will miscompile.

### 4.3 “Always activate”

`this+4 != 0` skips activate — adversarial residual: when parents set `+4` is not dualed here (OWN-ONLY).

### 4.4 Latch clear on null resolve

Still clears `+0x38` — ports that only clear on success leave the event stuck “active”.

---

## 5. Open questions

1. Product English for vtbl `+0x1bc`.  
2. Writers of `this+4` and `this+0x68` outside this VA.  
3. Runtime capture of airlift phase 4→5.

**Verdict:** **accept-with-gaps**
