# Review B (skeptical / adversarial): `aa_004f8430` WeaponTrack_UpdateAimYaw_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8430` |
| **VA** | `0x004f8430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f8430_WeaponTrack_UpdateAimYaw_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Applies heat / fire cost each track tick | **Falsified** | no CanFire / AddHeat / pool math |
| 2 | Always updates yaw | **Falsified** | early-out if `+8==0` or no selected slot or non-finite basis |
| 3 | Always tracks selected target | **Falsified** | free-slew branch when phys/target gate fails and `+0x103==0` |
| 4 | Angle wrap uses degrees | **Falsified** | `2π` / `±π` constants from `read_memory` |
| 5 | Same as turret aim full solver | **Falsified** | only stores scalar `+0x158` yaw path; no full 3-axis turret package here |
| 6 | Clears target whenever far | **Falsified** | needs `‖δ‖>240` **and** selected vcall path + `*(char*)(iVar4+0x6b9)==0` |

---

## 2. Surviving contract

```
if host && selected_slot:
  basis = extract(hardpoint)
  if finite:
    resolve target_xz OR free-slew
    dt = client_ms_delta → seconds; stamp last-tick
    update this+0x158 (wrap 0..2π) toward goal
    maybe clear selected if too far + flag
```

**Verdict:** **accept-with-gaps**
