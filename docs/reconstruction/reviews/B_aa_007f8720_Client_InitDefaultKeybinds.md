# Skeptical / adversarial review B: `Client_InitDefaultKeybinds` @ `0x007f8720`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f8720` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | `2026-07-23` |
| **Scope** | Default DIK table claims, ActionMap register ABI, drive-bind linkage |
| **Counterpart** | `reviews/A_aa_007f8720_Client_InitDefaultKeybinds.md` |
| **Verdict** | **needs-more-evidence** (for seal); **body CF not broken** |

**Generic approval is insufficient.** This review attacks naming, DIK→action labels, helper roles, and over-claims that this function seeds Accelerate/Steer keys used by DriveControlTick.

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_007f8720_Client_InitDefaultKeybinds.md` | Immutable decompile capture |
| `reconstructed-exact/Client_InitDefaultKeybinds.cpp` | Sectioned clean |
| `reconstructed-exact/Client_ActionMap_Init.cpp` | Parent zero-fill + call order |
| `reconstructed-exact/Client_InitActionDisplayNames.cpp` | Name strings for slots (incl. Accelerate/Steer) |
| `systems/input-drive-control.md` | Held-flag DAT_* consumed by DriveControlTick |
| Fresh re-decompile `0x007f8720` | Confirm raw not stale |

**Not performed:** CE dump of ActionMap after init; single-step of `FUN_007f74a0` / `FUN_007f72e0`; correlation of Inventory DIK to `DAT_00d1bc*` family.

---

## 2. Attacks / falsification attempts

### 2.1 “This function sets default Accelerate/Steer/Brake keys”

**Attack:** DriveControlTick depends on held flags `DAT_00d1bc26` (Accel) etc. Does InitDefaultKeybinds write those DIKs?

**Result:** **Not shown in this body.** Explicit immediates cover UI (Inventory `0x17`, QB `2..0x0B`, map `0x32`, etc.). Drive names exist in **InitActionDisplayNames** (`+0x27d` Accelerate … `+0x3b5` Brake), but corresponding DIK defaults are **not** named stores in InitDefaultKeybinds. They may hide in `FUN_007f74a0` or the `FUN_007f72e0` bursts — **unproven**.

**Impact:** Plates that imply “keybind init configures drive axes” over-claim unless scoped to “ActionMap table includes drive slots; DIK seeding for thr/steer open.”

### 2.2 `pActionMap` / register ABI

**Attack:** Clean renames `unaff_EDI` → `pActionMap`. Is that object definitely ActionMap?

**Result:** **Strong context, not bit-proven.** Parent `Client_ActionMap_Init` zeros an ESI object then calls this with no stack args; display-names use EAX. Register-passing ctor pattern is consistent. Mis-identifying the type would not change CF fidelity of stores.

### 2.3 Inventory / QB DIK labels

**Attack:** Clean plate says Inventory `0x17` (I) and QB `2..0x0B`.

**Result:** **Immediates High; human labels Probable.** Raw plate comment already states Inventory `0x17` and QB `2..0x0B`. DIK_I = `0x17` and DIK_1..0 = `0x02..0x0B` are standard DirectInput — consistent but not runtime-proven against UI strings.

### 2.4 Decimal `4000` secondary key store

**Attack:** Is clean inventing `0xfa0`?

**Result:** **No.** Raw uses decimal `4000` for one secondary u16; clean preserves decimal form and notes equivalence. Good.

### 2.5 `FUN_007f72e0` call counts

**Attack:** Did clean drop or add helper calls?

**Result:** Spot-check against raw: large mode-`2` block, enable bytes, second mode-`2` block, mode-`3` block — order matches. Exact count seal would need a mechanical diff (recommended before claiming bit-complete).

### 2.6 Section banners inventing CF

**Attack:** Do SECTION comments add branches?

**Result:** **No.** Comments group existing sequential if-stores; no extra conditions introduced in code.

---

## 3. What survives skepticism

| Claim | Survives? |
|---|---|
| Clean CF ≡ raw for visible DIK if-stores | **Yes** |
| Inventory `0x17` / QB `2..0x0B` immediates | **Yes** (raw) |
| Called from ActionMap_Init after display names | **Yes** |
| Drive thr/steer DIK defaults written here | **No / open** |
| Helper semantics | **Open** |
| Link from these DIKs to DriveControlTick DAT_* | **Open** (needs table map + runtime) |

---

## 4. Required evidence for seal

1. Decompile or reconstruct `FUN_007f74a0` and `FUN_007f72e0` (mode 2/3).
2. Map ActionMap slot offsets → global held flags `DAT_00d1bc*`.
3. Runtime: after init, read DIK fields for Accelerate/Steer/Brake slots.
4. Optional: mechanical line-diff clean vs raw for helper call counts.

---

## 5. Verdict

Body transcription is sound; **drive-control semantic completeness of this unit is not sealed**. Treat as ActionMap default DIK filler with high CF confidence and open helper/drive-seed gaps.

**needs-more-evidence** (for complete unit seal); reconstruction fidelity of transcribed stores remains acceptable.
